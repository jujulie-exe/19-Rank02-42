/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:44 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/21 19:09:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 150

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

typedef struct s_fractal {
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	zoom;
} t_fractal;

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_fractal	*fractal;
} t_data;

int	get_smooth_color(int iter, double z_re, double z_im);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	check_key(t_fractal *fractal, int keycode, t_data *data);
void	calulate_complex_coords(int x, int y, t_fractal *fractal, double *c_re, double *c_im, double aspect_ratio);
void	draw_mandelbrot(t_fractal *fractal, t_data *data);
int	mandelbrot(double c_re, double c_im, double *z_re_out, double *z_im_out);
void	init_fra(t_fractal *fractal);
int	julia(double z_re, double z_im, double c_re, double c_im);
void	draw_julia(t_fractal *fractal, t_data  *data, double c_re, double c_im);

#endif
