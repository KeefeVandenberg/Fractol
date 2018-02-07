/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:13:18 by kvandenb          #+#    #+#             */
/*   Updated: 2018/02/06 17:50:09 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			splitter(char *str, t_env *e)
{
	if (e->fract == 0)
	{
		if (ft_strequ("mandelbrot", str))
			e->fract = 1;
		if (ft_strequ("julia", str))
			e->fract = 2;
		if (ft_strequ("burningship", str))
			e->fract = 3;
		draw(e);
	}
	return (0);
}

int			draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->window);
	if (e->fract == 1)
	{
		mandelbrot(e);
		controls(e);
	}
	if (e->fract == 2)
	{
		thread_creator(e);
		controls(e);
	}
	if (e->fract == 3)
	{
		burningship(e);
		controls(e);
	}
	if (e->fract == 0)
	{
		ft_printusage();
		ft_exit(e);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = init_env();
	e->mlx = mlx_init();
	e->window = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol");
	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->image_ptr = mlx_get_data_addr(e->image,
		&(e->bpp), &(e->sl), &(e->endian));
	splitter(av[1], e);
	mlx_hook(e->window, 4, 0, mouse_hook, e);
	mlx_hook(e->window, 2, 0, key_down, e);
	mlx_hook(e->window, 5, 0, mouse_unhook, e);
	mlx_hook(e->window, 6, 0, motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
