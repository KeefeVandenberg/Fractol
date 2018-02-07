/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:33:55 by kvandenb          #+#    #+#             */
/*   Updated: 2018/02/03 16:38:19 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_unhook(int button, int x, int y, t_env *all)
{
	all->events->mouse = 0;
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *all)
{
	int		shiftx;
	int		shifty;

	if (button == 5)
		all->events->zoom -= (all->events->zoom / 10);
	if (button == 4)
		all->events->zoom += (all->events->zoom / 10);
	all->events->intial_x = x;
	all->events->intial_y = y;
	draw(all);
	return (0);
}

int			motion_hook(int x, int y, t_env *all)
{
	if (x <=
		WIDTH - 1 && y <= HEIGHT - 1 && y >= 0 && x >= 0 && all->fract == 2)
	{
		all->events->julia_a = ((double)x / (WIDTH));
		all->events->julia_b = ((double)y / (WIDTH));
		if (all->events->julia_a > 2.0)
			all->events->julia_a = all->events->julia_b - 2.0;
		if (all->events->julia_b > 2.0)
			all->events->julia_b = all->events->julia_b - 2.0;
		if (all->events->julia_a < .999)
			all->events->julia_a *= -1;
		else
			all->events->julia_a -= 1;
		if (all->events->julia_b <= .999)
			all->events->julia_b *= -1;
		else
			all->events->julia_b -= 1;
		draw(all);
	}
	return (0);
}

int			hook_keydown(int k, t_env *all)
{
	double	zoom;

	zoom = all->events->zoom;
	if (k == 53)
		exit(1);
	if ((k == 13 || k == 1 || k == 126 || k == 125
		|| k == 123 || k == 124 || k == 35))
	{
		if (k == 13)
			all->events->zoom -= (zoom / 10);
		else if (k == 1)
			all->events->zoom += zoom / 10;
		else if (k == 125)
			all->events->yshift += .01 * zoom * 2;
		else if (k == 126)
			all->events->yshift -= .01 * zoom * 2;
		else if (k == 123)
			all->events->xshift -= .01 * zoom * 2;
		else if (k == 124)
			all->events->xshift += .01 * zoom * 2;
	}
	return (0);
}

int			key_down(int keycode, t_env *e)
{
	if (keycode == 116)
		e->iter += 10;
	if (keycode == 121 && e->iter > 10)
		e->iter -= 10;
	if (keycode == 115 && e->man->color <= 555745280)
		e->man->color *= 2;
	if (keycode == 119 && e->man->color > 100)
		e->man->color /= 5;
	if (keycode == 107)
		e->events->crosshair = e->events->crosshair ? 0 : 1;
	hook_keydown(keycode, e);
	draw(e);
	return (0);
}
