/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:57:20 by agaussel          #+#    #+#             */
/*   Updated: 2026/01/27 14:39:34 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_config *a)
{
	if (a->img)
		mlx_destroy_image(a->mlx, a->img);
	if (a->win)
		mlx_destroy_window(a->mlx, a->win);
	if (a->mlx)
	{
		mlx_destroy_display(a->mlx);
		free(a->mlx);
	}
	exit(0);
}

int	key_press(int keycode, t_config *a)
{
	if (keycode == ESC_KEY)
		close_window(a);
	else if (keycode == 61 || keycode == 86)
		a->zoom *= 1.2;
	else if (keycode == 45 || keycode == 82)
		a->zoom /= 1.2;
	else if (keycode == 65362)
		a->center_i -= 20.0 / a->zoom;
	else if (keycode == 65364)
		a->center_i += 20.0 / a->zoom;
	else if (keycode == 65361)
		a->center_r -= 20.0 / a->zoom;
	else if (keycode == 65363)
		a->center_r += 20.0 / a->zoom;
	else
		return (0);
	render_fractal(a);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_config *a)
{
	(void)x;
	(void)y;
	if (button == 4)
		a->zoom *= 1.2;
	else if (button == 5)
		a->zoom /= 1.2;
	else
		return (0);
	render_fractal(a);
	return (0);
}
