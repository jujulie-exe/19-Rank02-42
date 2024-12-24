
#include "fractol.h"

int	mouse_hook(int button,int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	x += 1;
	y += 1;
	x = 0;
	y = 0;
	if (button == 4)
	{
		zoom(data->fractal, 0.9, false, data);
		return (1);
	}
	else if (button == 5)
	{
		zoom(data->fractal, 0.9, true, data);
		return (1);
	}
	return (0);
}
int track_mouse(int x, int y, t_data *data)
{
	static int	frame_counter = 0;
	const int	debounce_frame = 45;

	if(data->fractal->julia == true)
	{
		const double attenuation_factor = 0.001 * pow(0.9, data->fractal->zoom);
		
		double target_real;
		double target_imag;
		target_real = (map(x, 0, WIDTH, data->fractal->min_re, data->fractal->max_re) * data->fractal->zoom)  + data->fractal->shift_x;
		target_imag = (map(y, 0, HEIGHT, data->fractal->min_im, data->fractal->max_im) * data->fractal->zoom) + data->fractal->shift_y;
		target_real += data->fractal->zoom + data->fractal->shift_x;
		target_imag += data->fractal->zoom + data->fractal->shift_y;
		data->fractal->real += (target_real - data->fractal->real) * attenuation_factor;
		data->fractal->imag += (target_imag - data->fractal->imag) * attenuation_factor;
		frame_counter++;
		if (frame_counter >= debounce_frame)
		{
			draw_julia(data->fractal, data, data->fractal->real, data->fractal->imag);
			frame_counter = 0;
		}
	}
	return (0);
}
double get_shift_factor(t_fractal *fractal)
{
	double factor;
	factor = 0.001 * pow(0.9, fractal->zoom);
	return (factor);
}

int	check_key(t_fractal *fractal, int keycode, t_data *data)
{
	if (keycode == 65364)
		move(fractal, 0.9, false, data);
	else if (keycode == 65362)
		move(fractal, 0.9, true, data);
	else if (keycode == 65361)
		move_slide(fractal, 0.9, false, data);
	else if (keycode == 65363)
		move_slide(fractal, 0.9, true, data);
	else if (keycode == 114)
		swift_color(fractal, data);
	else if (keycode == 119)
		move(fractal, get_shift_factor(fractal), false, data);
	else if (keycode == 115)
		move(fractal, get_shift_factor(fractal), true, data);
	else if (keycode == 100)
		move_slide(fractal, get_shift_factor(fractal), true, data);
	else if (keycode == 97)
		move_slide(fractal, get_shift_factor(fractal), false, data);
	else if (keycode == 65307)
		exit_err(data);
	return (0);

}
int	key_hook(int keycode, t_data *data)
{
	int i;
	i = check_key(data->fractal, keycode, data);
	return (i);
}

int	manager_hook(t_data *data, t_fractal *fractal)
{
	data->fractal = fractal;

	mlx_hook(data->win, 2, (1L<<0), key_hook,&data);
	//mlx_hook(data->win, 4, (1L<<2), mouse_hook,&data);
	//mlx_mouse_hook(data->win, mouse_hook, &data);
	//mlx_hook(data->win, 2, (1L<<0), key_hook,&data);
	return (0);
}
