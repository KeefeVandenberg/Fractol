/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:50:29 by kvandenb          #+#    #+#             */
/*   Updated: 2018/01/27 14:00:51 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define THREAD_NUM 4
# define WHITE 0

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "minilibx_macos/mlx.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "GNL/libft/libft.h"
# include "GNL/get_next_line.h"
# include "math.h"

typedef struct		s_man
{
	double			previous_a;
	double			previous_b;
	double			y;
	double			x;
	double			a;
	double			zx;
	double			zy;
	double			b;
	int				color;
}					t_man;

typedef struct		s_threads
{
	pthread_t		thread[4];
}					t_threads;

typedef struct		s_events
{
	int				pageup;
	int				pagedown;
	int				crosshair;
	int				intial_x;
	int				intial_y;
	int				mouse;
	double			zoom;
	double			yshift;
	double			xshift;
	int				colorshift;
	double			julia_a;
	double			julia_b;
}					t_events;

typedef struct		s_env
{
	t_threads		*threads;
	t_man			*man;
	t_events		*events;
	void			*mlx;
	void			*image;
	void			*image_ptr;
	void			*window;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				iter;
	int				maxiter;
}					t_env;

typedef struct		s_trd
{
	double			a;
	double			b;
	double			previous_a;
	double			previous_b;
	double			zx;
	double			zy;
	int				x;
	int				y;
	int				n;
}					t_trd;

typedef struct		s_burning
{
	double			x0;
	double			y0;
	double			xtmp;
	double			ytmp;
	double			x;
	double			y;
	int				px;
	int				py;
	int				n;
}					t_burning;

double				magnitude(t_env *e);
t_man				*square(t_man *man);
void				add_thread(t_trd *all);
t_trd				*square_thread(t_trd *all);
t_trd				*enviroment_cpy(t_env *j);
void				pixel_put_img(t_env *j, int x, int y, int color);
void				add_julia_ab(t_trd *all, t_env *e);
int					draw(t_env *e);
int					splitter(char *str, t_env *e);
void				find_julia_ab(t_trd *all, t_env *e);

t_env				*init_env(void);
t_trd				*enviroment_cpy(t_env *j);

int					key_up(int keycode, t_env *e);
int					key_down(int keycode, t_env *e);
int					hook_keydown(int k, t_env *all);
int					motion_hook(int x, int y, t_env *all);
int					mouse_hook(int button, int x, int y, t_env *all);
int					mouse_unhook(int button, int x, int y, t_env *all);
void				crosshair(t_env *all);

void				*thread_1(void *j);
void				*thread_2(void *j);
void				*thread_3(void *j);
void				*thread_4(void *j);
int					*thread_creator(t_env *j);

void				mandelbrot_scale(t_env *e);
void				mandelbrot(t_env *j);
void				controls(t_env *j);
void				controls_helper(t_env *j);

void				burningship(t_env *j);
void				burning_iter(t_burning *e);
int					ft_printusage(void);

#endif
