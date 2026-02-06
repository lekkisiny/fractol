/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:11:18 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_fractal_type(char *arg, t_config *fra)
{
	if (is_str_equal(arg, "mandelbrot"))
	{
		fra->type = MANDELBROT;
		return (1);
	}
	if (is_str_equal(arg, "julia"))
	{
		fra->type = JULIA;
		return (1);
	}
	return (0);
}

static void	init_fractal_config(t_config *fra)
{
	fra->type = FRACTAL_NONE;
	fra->max_iter = 100;
	fra->zoom = WIDTH / 4.0;
	fra->center_r = 0.0;
	fra->center_i = 0.0;
}

static int	parse_julia(int ac, char **av, t_config *fra)
{
	if (ac != 4)
		return (0);
	fra->julia_r = atof(av[2]);
	fra->julia_i = atof(av[3]);
	fra->center_r = 0.0;
	return (1);
}

int	parser(int ac, char **av, t_config *fra)
{
	init_fractal_config(fra);
	if (ac < 2)
		return (0);
	if (!parse_fractal_type(av[1], fra))
		return (0);
	if (fra->type == JULIA)
		return (parse_julia(ac, av, fra));
	else if (fra->type == MANDELBROT)
	{
		if (ac != 2)
			return (0);
		fra->center_r = -0.5;
	}
	return (1);
}


