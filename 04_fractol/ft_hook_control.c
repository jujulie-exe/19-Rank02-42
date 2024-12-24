
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
    const double attenuation_factor = 0.001; // Valore tra 0 e 1 per ridurre la velocità di cambiamento
    double target_real;
    double target_imag;
	target_real = (map(x, 0, WIDTH, data->fractal->min_re, data->fractal->max_re) * data->fractal->zoom)  + data->fractal->shift_x;
	target_imag = (map(y, 0, HEIGHT, data->fractal->min_im, data->fractal->max_im) * data->fractal->zoom) + data->fractal->shift_y;
    target_real += data->fractal->zoom; // Aggiungi shift_x se necessario
    target_imag += data->fractal->zoom; // Aggiungi shift_y se necessario
    data->fractal->real += (target_real - data->fractal->real) * attenuation_factor;
    data->fractal->imag += (target_imag - data->fractal->imag) * attenuation_factor;
    draw_julia(data->fractal, data, data->fractal->real, data->fractal->imag);

    return (0);
}

int	check_key(t_fractal *fractal, int keycode, t_data *data)
{
	if (keycode == 65364)
		move(fractal, 0.2, false, data);
	else if (keycode == 65362)
		move(fractal, 0.2, true, data);
	else if (keycode == 65361)
		move_slide(fractal, 0.01, false, data);
	else if (keycode == 65363)
		move_slide(fractal, 0.01, true, data);
	else if (keycode == 114)
		swift_color(fractal, data);
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
