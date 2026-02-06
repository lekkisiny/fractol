/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
	ft_printf("\nOptions:\n");
	ft_printf("  mandelbrot           Display Mandelbrot set\n");
	ft_printf("  julia r i            Display Julia set with parameters\n");
	exit(1);
}

void	exitmanager(int code)
{
	static const char	*messages[] = {
		"Programme terminé avec succès.",
		"Erreur : allocation mémoire échouée.",
		"Erreur inconnue."
	};

	if (code == EXIT_OK)
		(ft_printf("%s\n", messages[code]), exit(EXIT_SUCCESS));
	else
		(ft_printf("%s\n", messages[code]), exit(EXIT_FAILURE));
}
