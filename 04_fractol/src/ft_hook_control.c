
#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_data *data)
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

double	get_shift_factor(t_fractal *fractal)
{
	double	factor;

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
	int	i;

	i = check_key(data->fractal, keycode, data);
	return (i);
}
