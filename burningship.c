/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:05:42 by kvandenb          #+#    #+#             */
/*   Updated: 2018/02/06 17:39:11 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burningship(t_env *j)
{
	int			hex;
	t_burning	*e;

	e = (t_burning *)malloc(sizeof(t_burning));
	e->px = -1;
	while (e->px++ != WIDTH)
	{
		e->py = -1;
		while (e->py++ != HEIGHT)
		{
			e->x0 = ((double)(e->px - (WIDTH / 2)) /
				(double)(WIDTH / 4) * j->events->zoom + j->events->xshift);
			e->y0 = ((double)(e->py - (HEIGHT / 2)) /
				(double)(HEIGHT / 4) * j->events->zoom + j->events->yshift);
			e->x = 0;
			e->y = 0;
			e->n = 0;
			while (e->n != j->iter && e->x * e->x + e->y * e->y <= 4.0)
				burning_iter(e);
			e->n == j->iter ? pixel_put_img(j, e->px, e->py, 0x000000)
				: pixel_put_img(j, e->px, e->py, e->n * j->man->color);
		}
	}
	free(e);
	mlx_put_image_to_window(j->mlx, j->window, j->image, 0, 0);
}

void			burning_iter(t_burning *e)
{
	e->xtmp = e->x;
	e->x = e->x * e->x - e->y * e->y + e->x0;
	e->y = 2 * fabs(e->y * e->xtmp) + e->y0;
	e->n += 1;
}
