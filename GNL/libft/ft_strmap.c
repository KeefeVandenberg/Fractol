/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:39:04 by kvandenb          #+#    #+#             */
/*   Updated: 2017/10/05 15:42:03 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (!(s))
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str)
	{
		while (i < ft_strlen(s))
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
