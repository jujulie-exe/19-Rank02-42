
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

int	check_key(t_fractal *fractal, int keycode, t_data *data)
{
	if (keycode == 4)
	{
		zoom(fractal, 0.9, false, data);
		return (1);
	}
	else if (keycode == 5)
	{
		zoom(fractal, 0.9, true, data);
		return (1);
	}
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
