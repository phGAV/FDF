/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:39:53 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/28 15:54:40 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hopchr(char *s, char c)
{
	char *p;

	p = s;
	while (*p && *p == c)
		p++;
	return (p - s);
}

static size_t	ft_hopwrd(char *s, char c)
{
	char *p;

	p = s;
	while (*p && *p != c)
		p++;
	return (p - s);
}

static size_t	ft_wrdcnt(char *s, char c)
{
	size_t ret;

	ret = 0;
	while (*(s += ft_hopchr(s, c)))
	{
		s += ft_hopwrd(s, c);
		ret++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**pv;
	char	**ppv;
	char	*ps;
	size_t	w;

	if (!s)
		return (NULL);
	ps = (char *)s;
	w = ft_wrdcnt(ps, c);
	if ((pv = (char **)malloc(sizeof(char *) * (w + 1))))
	{
		ppv = pv;
		while (w--)
		{
			ps += ft_hopchr(ps, c);
			if (!(*ppv++ = ft_strndup(ps, ft_hopwrd(ps, c))))
				return (ft_pvdel((void **)pv));
			ps += ft_hopwrd(ps, c);
		}
		*ppv = NULL;
	}
	return (pv);
}
