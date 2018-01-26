/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:35:24 by kvandenb          #+#    #+#             */
/*   Updated: 2018/01/25 19:19:02 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_scale(t_env *e)
{
	e->man->a = ((double)(e->man->x - (WIDTH / 2)) /
	(double)(WIDTH / 4) * e->events->zoom + e->events->xshift);
	e->man->b = ((double)(e->man->y - (HEIGHT / 2)) /
		(double)(HEIGHT / 4) * e->events->zoom + e->events->yshift);
	e->man->previous_a = e->man->a;
	e->man->previous_b = e->man->b;
}

void		mandelbrot(t_env *j)
{
	int		n;
	t_env	*e;
	int		hex;

	e = j;
	e->man->x = -1;
	while (e->man->x++ != WIDTH)
	{
		e->man->y = -1;
		while (e->man->y++ != HEIGHT)
		{
			mandelbrot_scale(e);
			n = 0;
			while (++n != e->iter &&
				(sqrt((e->man->a * e->man->a) + (e->man->b * e->man->b)) < 3.0))
			{
				square(e->man);
				e->man->a = e->man->zx + e->man->previous_a;
				e->man->b = e->man->zy + e->man->previous_b;
			}
			e->iter == n ? pixel_put_img(e, e->man->x, e->man->y, 0) :
				pixel_put_img(e, e->man->x, e->man->y, n * e->man->color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_man		*square(t_man *man)
{
	double	tmp;

	tmp = (man->a * man->a) - (man->b * man->b);
	man->zy = 2 * man->a * man->b;
	man->zx = tmp;
	return (man);
}

void		controls(t_env *j)
{
	int		i;

	i = 0;
	controls_helper(j);
	if (j->events->crosshair == 1)
	{
		i = WIDTH / 2 - 11;
		while (i++ != (WIDTH / 2 + 10))
			mlx_pixel_put(j->mlx, j->window, i, HEIGHT / 2, 0xFF0000);
		i = HEIGHT / 2 - 11;
		while (i++ != (HEIGHT / 2 + 10))
			mlx_pixel_put(j->mlx, j->window, WIDTH / 2, i, 0xFF0000);
	}
}

void		controls_helper(t_env *j)
{
	char	*iter;

	iter = ft_itoa(j->iter);
	iter = ft_strjoin("iterations : ", iter);
	mlx_string_put(j->mlx, j->window, 10, 0, 0xFFFFFF, iter);
	mlx_string_put(j->mlx, j->window, 10,
	20, 0xFFFFFF, "Add iterations PAGEUP");
	mlx_string_put(j->mlx, j->window, 10,
	40, 0xFFFFFF, "Minus iterations PAGEDOWN");
	mlx_string_put(j->mlx, j->window,
	10, 60, 0xFFFFFF, "Change color with HOME / END");
	mlx_string_put(j->mlx, j->window, 10,
	80, 0xFFFFFF, "Toggle Crosshair with F14\n");
	mlx_string_put(j->mlx, j->window, 10, 100, 0xFFFFFF, "move up    ^\n");
	mlx_string_put(j->mlx, j->window, 10, 120, 0xFFFFFF, "move down  v\n");
	mlx_string_put(j->mlx, j->window, 10, 140, 0xFFFFFF, "move right >\n");
	mlx_string_put(j->mlx, j->window, 10, 160, 0xFFFFFF, "move left  <\n");
	mlx_string_put(j->mlx, j->window, 10,
		180, 0xFFFFFF, "zoom in and out with W / S");
}
