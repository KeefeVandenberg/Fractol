/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:09:06 by kvandenb          #+#    #+#             */
/*   Updated: 2018/02/06 17:39:46 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*thread_1(void *j)
{
	t_env	*e;
	t_trd	*all;

	e = j;
	all = (t_trd *)malloc(sizeof(t_trd));
	all->x = 0;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = -1;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while (++all->n != e->iter && (sqrt((all->a * all->a)
				+ (all->b * all->b)) < 2.0))
				square_thread(all);
			all->n == e->iter ? pixel_put_img(e, all->x, all->y, 0)
				: pixel_put_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void		*thread_2(void *j)
{
	t_env	*e;
	t_trd	*all;

	e = j;
	all = (t_trd *)malloc(sizeof(t_trd));
	all->x = -1;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = WIDTH / 2;
		while (all->y++ != WIDTH)
		{
			find_julia_ab(all, e);
			while (++all->n != e->iter && (sqrt((all->a * all->a)
				+ (all->b * all->b)) < 2.0))
				square_thread(all);
			all->n == e->iter ? pixel_put_img(e, all->x, all->y, 0)
				: pixel_put_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void		*thread_3(void *j)
{
	t_env	*e;
	t_trd	*all;

	e = j;
	all = (t_trd *)malloc(sizeof(t_trd));
	all->x = WIDTH / 2;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH)
	{
		all->y = WIDTH / 2;
		while (all->y++ != WIDTH)
		{
			find_julia_ab(all, e);
			while (++all->n != e->iter && (sqrt((all->a * all->a)
				+ (all->b * all->b)) < 2.0))
				square_thread(all);
			all->n == e->iter ? pixel_put_img(e, all->x, all->y, 0)
				: pixel_put_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void		*thread_4(void *j)
{
	t_env	*e;
	t_trd	*all;

	e = j;
	all = (t_trd *)malloc(sizeof(t_trd));
	all->x = WIDTH / 2;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH)
	{
		all->y = 0;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while (++all->n != e->iter && (sqrt((all->a * all->a)
				+ (all->b * all->b)) < 2.0))
				square_thread(all);
			all->n == e->iter ? pixel_put_img(e, all->x, all->y, 0)
				: pixel_put_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

int			*thread_creator(t_env *e)
{
	int		i;

	i = 1;
	pthread_create(&e->threads->thread[1], NULL, thread_1, e);
	pthread_create(&e->threads->thread[2], NULL, thread_2, e);
	pthread_create(&e->threads->thread[3], NULL, thread_3, e);
	pthread_create(&e->threads->thread[4], NULL, thread_4, e);
	while (i != 4)
	{
		pthread_join(e->threads->thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
	return (0);
}
