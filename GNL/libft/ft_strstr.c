/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:53:24 by kvandenb          #+#    #+#             */
/*   Updated: 2017/09/25 21:20:54 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *large, const char *small)
{
	int i;
	int x;

	i = 0;
	if (!*small)
		return ((char *)large);
	while (large[i])
	{
		x = 0;
		while ((large[i] == small[x]) && large[i])
		{
			i++;
			x++;
		}
		if (!small[x])
			return ((char *)&large[i - x]);
		i = i - x + 1;
	}
	return (NULL);
}
