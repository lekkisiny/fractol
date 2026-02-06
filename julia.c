/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia(t_config *a, int x, int y, t_complex *z)
{
	z->r = (x - WIDTH / 2.0) / a->zoom + a->center_r;
	z->i = (y - HEIGHT / 2.0) / a->zoom + a->center_i;
}

static int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	tmp;
	double	z_squared;

	iter = 0;
	z_squared = z.r * z.r + z.i * z.i;
	while (z_squared <= 4.0 && iter < max_iter)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		iter++;
		z_squared = z.r * z.r + z.i * z.i;
	}
	return (iter);
}

static void	render_julia_line(t_config *a, int y)
{
	t_complex	z;
	t_complex	c;
	int			x;
	int			iter;

	c.r = a->julia_r;
	c.i = a->julia_i;
	x = 0;
	while (x < WIDTH)
	{
		init_julia(a, x, y, &z);
		iter = calculate_julia(z, c, a->max_iter);
		put_pixel(a, x, y, colorpicker(iter, a->max_iter));
		x++;
	}
}

void	*render_julia_thread(void *arg)
{
	t_thread_data	*data;
	t_config		*a;
	int				y;

	data = (t_thread_data *)arg;
	a = data->config;
	y = data->start_y;
	while (y < data->end_y)
	{
		render_julia_line(a, y);
		y++;
	}
	return (NULL);
}
