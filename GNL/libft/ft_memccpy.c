/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:53:48 by kvandenb          #+#    #+#             */
/*   Updated: 2017/09/24 18:29:37 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)s1++ = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return (s1);
		s2++;
	}
	return (0);
}
