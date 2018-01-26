/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarry_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:24:57 by kvandenb          #+#    #+#             */
/*   Updated: 2017/10/09 14:31:06 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray_fd(char **array, int fd)
{
	if (!array)
		return ;
	while (*array)
		ft_putendl_fd(*array++, fd);
}
