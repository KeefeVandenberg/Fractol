/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 14:02:57 by kvandenb          #+#    #+#             */
/*   Updated: 2017/09/24 14:03:27 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((unsigned int)c >= 'A' && (unsigned int)c <= 'Z')
		|| ((unsigned int)c >= 'a' && (unsigned int)c <= 'z'))
		return (1);
	else
		return (0);
}
