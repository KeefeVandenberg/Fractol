/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:06:11 by kvandenb          #+#    #+#             */
/*   Updated: 2017/10/05 18:24:48 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*filler(char const *str, char c, unsigned int *index)
{
	unsigned	i;
	unsigned	start;
	char		*word;

	while (str[*index] == c && str[*index] != '\0')
		(*index)++;
	start = *index;
	while (str[*index] != c && str[*index] != '\0')
		(*index)++;
	word = ft_strnew(*index - start);
	if (!word)
		return (NULL);
	i = 0;
	while (start < *index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned	i;
	unsigned	j;
	unsigned	words;
	char		**rtn;

	if (!(s))
		return (NULL);
	i = -1;
	words = 0;
	while (s[++i] != '\0')
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
	i = 0;
	j = 0;
	if (!(rtn = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		rtn[i] = filler(s, c, &j);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
