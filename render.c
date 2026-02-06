/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <agaussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by agaussel          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_config *a)
{
	a->max_iter = calculate_max_iter(a->zoom);
	if (a->type == MANDELBROT)
		render_mandelbrot(a);
	else if (a->type == JULIA)
		render_julia(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}

void	create_threads(t_config *a, pthread_t *threads,
			t_thread_data *thread_data, void *(*func)(void *))
{
	int	rows_per_thread;
	int	i;

	rows_per_thread = HEIGHT / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].config = a;
		thread_data[i].start_y = i * rows_per_thread;
		if (i == NUM_THREADS - 1)
			thread_data[i].end_y = HEIGHT;
		else
			thread_data[i].end_y = (i + 1) * rows_per_thread;
		pthread_create(&threads[i], NULL, func, &thread_data[i]);
		i++;
	}
}

void	join_threads(pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	render_julia(t_config *a)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];

	create_threads(a, threads, thread_data, render_julia_thread);
	join_threads(threads);
}

void	render_mandelbrot(t_config *a)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];

	create_threads(a, threads, thread_data, render_mandelbrot_thread);
	join_threads(threads);
}
