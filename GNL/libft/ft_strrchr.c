/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:15:46 by kvandenb          #+#    #+#             */
/*   Updated: 2017/09/21 13:24:21 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp_str;

	temp_str = s;
	temp_str = temp_str + ft_strlen(s);
	while (*temp_str != (char)c && temp_str != s)
		temp_str--;
	if (*temp_str == (char)c)
		return ((char *)temp_str);
	return (0);
}
