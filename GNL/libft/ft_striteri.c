/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:28:00 by kvandenb          #+#    #+#             */
/*   Updated: 2017/10/05 18:12:26 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned i;

	if (!(s && f))
		return ;
	i = ft_strlen(s);
	while (i > 0)
	{
		i--;
		f(i, &s[i]);
	}
}
