/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:36:51 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 22:21:33 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_w(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static	size_t	ft_skip(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static	size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	if (!s || !(arr = (char**)malloc(sizeof(char*) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (j < ft_count_w(s, c) && *(s + i) != '\0')
	{
		i = i + ft_skip(s + i, c);
		len = ft_len(s + i, c);
		if (!(arr[j] = ft_strsub(s, i, len)))
		{
			while (j--)
				free(arr[j]);
			free(arr);
			return (NULL);
		}
		j++;
		i += len;
	}
	arr[j] = NULL;
	return (arr);
}
