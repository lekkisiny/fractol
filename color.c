/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	extract_rgb(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

static int	blend_rgb(int r1, int r2, int g1, int g2, double blend)
{
	int	r;
	int	g;

	r = (int)(r1 * (1 - blend) + r2 * blend);
	g = (int)(g1 * (1 - blend) + g2 * blend);
	return ((r << 16) | (g << 8));
}

static int	blend_colors(int *colors, int index, int next_index, double blend)
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;

	extract_rgb(colors[index], &r1, &g1, &b1);
	extract_rgb(colors[next_index], &r2, &g2, &b1);
	b1 = (int)(b1 * (1 - blend) + ((colors[next_index]) & 0xFF) * blend);
	return (blend_rgb(r1, r2, g1, g2, blend) | b1);
}

int	colorpicker(int iter, int max_iter)
{
	int		colors[6];
	double	color_pos;
	int		idx;
	double	blend;

	colors[0] = 0x8B00FF;
	colors[1] = 0xFF4500;
	colors[2] = 0xFF0066;
	colors[3] = 0xCC00FF;
	colors[4] = 0xFF6600;
	colors[5] = 0xDD0033;
	if (iter == max_iter)
		return (0x0A0A2E);
	color_pos = ((double)iter / (double)max_iter) * 5;
	idx = (int)color_pos;
	blend = color_pos - idx;
	if (idx >= 5)
		return (colors[5]);
	return (blend_colors(colors, idx, idx + 1, blend));
}
