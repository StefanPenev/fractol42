/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:28:50 by spenev            #+#    #+#             */
/*   Updated: 2024/06/26 12:33:19 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../Libft/libft.h"
# include <mlx.h>
# include "keycodes.h"
# include <pthread.h>

# define WIDTH 800
# define HEIGHT 600
# define NUM_THREADS 8
# define ZOOM_IN_FACTOR 1.2
# define ZOOM_OUT_FACTOR 0.8
# define ITERATION_ADJUST_FACTOR 10

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	julia_c;
	int			max_iter;
	double		escape_radius;
	int			(*fractal_func)(struct s_data *data, t_complex c);
	int			color_offset;
	int			color_mode;
	double		zoom_factor;
	char		*fractal_type;
}			t_data;

typedef struct s_thread_data
{
	t_data	*data;
	int		start_y;
	int		end_y;
}				t_thread_data;

void	draw_fractal(t_data *data);
int		mandelbrot(t_data *data, t_complex c);
int		julia(t_data *data, t_complex c);
int		burning_ship(t_data *data, t_complex c);
int		handle_key(int key, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		close_window(t_data *data);
int		get_color(int iter, int max_iter, int color_offset, int color_mode);
int		parse_args(int argc, char **argv, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	help_msg(void);
double	ft_atof(const char *str);
void	set_defaults(t_data *data, char *fractal_type);

#endif
