/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:03 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/16 18:15:38 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_message(void)
{
	write(1, "Error: Missing or invalid argument.\n", 36);
	write(1, "Usage: ./fractol [mandelbrot | julia [real] [imaginary]]\n", 57);
	write(1,"Please specify either 'mandelbrot' or 'julia' as the argument.\n", 63);
	write(1, "For Julia set, the maximum valid range for real and imaginary parts is [-2.0, 2.0].\n", 84);
	exit(0);
}

void	init_julia(t_data *data, const char *s1, const char *s2)
{
	data->fractal->julia = true;
	data->fractal->real = ft_atof(s1);
	if(data->fractal->real < -2.0 || data->fractal->real > 2.0)
	{
		write(1, "Error: Imaginary part (%f) out of range. Valid range is [-2.0, 2.0].\n", 69);
		exit (0);
	}
	data->fractal->imag = ft_atof(s2);
	if(data->fractal->imag < -2.0 || data->fractal->imag > 2.0)
	{
		write(1, "Error: Real part (%f) out of range. Valid range is [-2.0, 2.0].\n", 64);
		exit(0);
	}
	data->fractal->zoom = 0.63;
	draw_julia(data->fractal, data, data->fractal->real, data->fractal->imag);
}
