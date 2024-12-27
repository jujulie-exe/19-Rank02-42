/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:44 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/27 14:51:58 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef MAX_ITER
#  define MAX_ITER 50
# endif

# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include "../minilibx/mlx.h"

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractal
{
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
	int		(*get_smooth_color)(int iter, double z_re, double z_im);
}	t_fractal;

typedef struct s_data
{
	t_fractal	*fractal;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_info
{
	int		x;
	int		y;
	double	aspect_ratio;
}	t_info;
typedef struct s_gt
{
	double	t;
	double	magnitude;
	double	smooth_iter;
}	t_gt;

void	move(t_fractal *fractal, double factor, bool up_or_down, t_data *data);
int		get_smooth_color_julia(int iter, int max_iter);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atof(const char *str);
void	init_julia(t_data *data, const char *s1, const char *s2);
int		get_smooth_color_limit(int iter, double z_re, double z_im);
int		get_smooth_color_basic(int iter, double z_re, double z_im);
int		get_smooth_color_pow(int iter, double z_re, double z_im);
void	swift_color(t_fractal *fractal, t_data *data);
void	move_slide(t_fractal *fractal, double factor,
			bool up_or_down, t_data *data);
int		get_smooth_color(int iter, double z_re, double z_im);
int		exit_err(t_data *data);
void	ft_message(void);
int		track_mouse(int x, int y, t_data *data);
void	my_mlx_pixel_put(t_data *data, t_info *info, int color);
int		check_key(t_fractal *fractal, int keycode, t_data *data);
void	draw_mandelbrot(t_fractal *fractala, t_data *data);
int		mandelbrot(double c_re, double c_im,
			double *z_re_out, double *z_im_out);
void	init_fra(t_fractal *fractal);
void	draw_julia(t_fractal *fractal, t_data *data, double c_re, double c_im);
int		manager_hook(t_data *data, t_fractal *fractal);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
void	zoom(t_fractal *fractal, double factor, bool check, t_data *data);
int		julia(double z_re, double z_im, double c_re, double c_im);

#endif
