/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:51:48 by kvandenb          #+#    #+#             */
/*   Updated: 2018/01/25 19:09:26 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->man = (t_man *)malloc(sizeof(t_man));
	e->events = (t_events *)malloc(sizeof(t_events));
	e->threads = (t_threads *)malloc(sizeof(t_threads));
	e->events->julia_a = -.73;
	e->events->julia_b = -.19;
	e->iter = 100;
	e->fract = 0;
	e->maxiter = 500;
	e->man->color = 265;
	e->events->colorshift = 150;
	e->events->zoom = 1;
	e->events->yshift = 0;
	e->events->yshift = 0;
	return (e);
}

t_trd		*enviroment_cpy(t_env *j)
{
	t_trd	*e;

	e = (t_trd *)malloc(sizeof(t_trd));
	if (j->fract == 2)
	{
		e->previous_a = j->events->julia_a;
		e->previous_b = j->events->julia_b;
	}
	return (e);
}
