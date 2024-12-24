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

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 75

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

typedef struct s_fractal {
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	shift_x;
	double	shift_y;
	double	zoom;
	bool	julia;
	double	real;
	double	imag;
	int (*get_smooth_color)(int iter, double z_re, double z_im);
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

void	move(t_fractal *fractal,double factor ,bool  up_or_down, t_data *data);
int	get_smooth_color_julia(int iter, double w_re, double w_im, double bailout);
double	 map(double value, double from_min, double from_max, double to_min, double to_max);
int 	get_smooth_color_limit(int iter, double z_re, double z_im);
int	get_smooth_color_basic(int iter, double z_re, double z_im);
int	get_smooth_color_pow(int iter, double z_re, double z_im);
void	swift_color(t_fractal *fractal,  t_data *data);
void	move_slide(t_fractal *fractal,double factor ,bool  up_or_down, t_data *data);
int	get_smooth_color(int iter, double z_re, double z_im);
int	track_mouse(int x, int y, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	check_key(t_fractal *fractal, int keycode, t_data *data);
void	calulate_complex_coords(int x, int y, t_fractal *fractal, double *c_re, double *c_im, double aspect_ratio);
void	draw_mandelbrot(t_fractal *fractal, t_data *data);
int	mandelbrot(double c_re, double c_im, double *z_re_out, double *z_im_out);
void	init_fra(t_fractal *fractal);
void	draw_julia(t_fractal *fractal, t_data  *data, double c_re, double c_im);
int	manager_hook(t_data *data, t_fractal *fractal);
int	key_hook(int keycode, t_data *data);
int	mouse_hook(int button,int x, int y, t_data *data);
void	zoom(t_fractal *fractal, double factor, bool check, t_data *data);
int	julia(double z_re, double z_im, double c_re, double c_im);

#endif
