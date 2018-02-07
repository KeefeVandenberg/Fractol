/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:33:42 by kvandenb          #+#    #+#             */
/*   Updated: 2018/02/03 17:01:23 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		add_thread(t_trd *all)
{
	all->a = all->zx + all->previous_a;
	all->b = all->zy + all->previous_b;
}

t_trd		*square_thread(t_trd *all)
{
	double	tmp;

	tmp = (all->a * all->a) - (all->b * all->b);
	all->zy = 2 * all->a * all->b;
	all->zx = tmp;
	add_thread(all);
	return (all);
}

void		pixel_put_img(t_env *j, int x, int y, int color)
{
	t_env	*e;
	int		hex;

	e = j;
	if (x < WIDTH && y < HEIGHT)
	{
		hex = mlx_get_color_value(e->mlx, color);
		ft_memcpy(e->image_ptr + 4 * WIDTH * y + x * 4, &hex, sizeof(int));
	}
}

void		find_julia_ab(t_trd *all, t_env *e)
{
	all->a = ((double)(all->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * e->events->zoom + e->events->xshift);
	all->b = ((double)(all->y - (HEIGHT / 2)) /
		(double)(HEIGHT / 4) * e->events->zoom + e->events->yshift);
	all->n = 0;
}

void		add_julia_ab(t_trd *all, t_env *e)
{
	t_trd	*j;

	j = all;
	j->previous_a = e->events->julia_a;
	j->previous_b = e->events->julia_b;
}
