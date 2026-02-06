/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:31:36 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_config	a;

	if (!parser(ac, av, &a))
		print_usage();
	if (!init_mlx(&a))
		exitmanager(1);
	mlx_hook(a.win, 17, 0, close_window, &a);
	mlx_key_hook(a.win, key_press, &a);
	mlx_mouse_hook(a.win, mouse_hook, &a);
	render_fractal(&a);
	mlx_loop(a.mlx);
}