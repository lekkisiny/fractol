/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx(t_config *a)
{
	a->mlx = mlx_init();
	if (!a->mlx)
		return (0);
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "fractol");
	if (!a->win)
		return (0);
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	if (!a->img)
		return (0);
	a->img_addr = mlx_get_data_addr(a->img, &a->bpp, &a->line_len, &a->endian);
	return (1);
}

void	put_pixel(t_config *a, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = a->img_addr + (y * a->line_len + x * (a->bpp / 8));
	*(unsigned int *)dst = color;
}

int	is_str_equal(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

int	calculate_max_iter(double zoom)
{
	int	max_iter;

	max_iter = 100 + (int)(log(zoom / 200.0) * 50);
	if (max_iter < 100)
		max_iter = 100;
	if (max_iter > 1000)
		max_iter = 1000;
	return (max_iter);
}
