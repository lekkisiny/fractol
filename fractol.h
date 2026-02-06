/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/03 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define ESC_KEY 65307
# define NUM_THREADS 4

# define EXIT_OK 0

typedef enum e_fractal_type
{
	FRACTAL_NONE,
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_config
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_fractal_type	type;
	int				max_iter;
	double			zoom;
	double			center_r;
	double			center_i;
	double			julia_r;
	double			julia_i;
}	t_config;

typedef struct s_thread_data
{
	t_config	*config;
	int				start_y;
	int				end_y;
}	t_thread_data;

/* Parser functions */
int		parser(int ac, char **av, t_config *fra);
int		parse_fractal_type(char *arg, t_config *fra);
void	print_usage(void);
void	exitmanager(int code);

/* Rendering functions */
void	render_fractal(t_config *a);
void	render_mandelbrot(t_config *a);
void	render_julia(t_config *a);
void	*render_mandelbrot_thread(void *arg);
void	*render_julia_thread(void *arg);

/* MLX and graphics functions */
int		init_mlx(t_config *a);
void	put_pixel(t_config *a, int x, int y, int color);
int		colorpicker(int iter, int max_iter);

/* Event handlers */
int		close_window(t_config *a);
int		key_press(int keycode, t_config *a);
int		mouse_hook(int button, int x, int y, t_config *a);

/* Utility functions */
int		is_str_equal(const char *s1, const char *s2);
int		calculate_max_iter(double zoom);

#endif
