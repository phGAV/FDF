/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:10:47 by diona             #+#    #+#             */
/*   Updated: 2019/09/14 19:11:13 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		ret;
	const char	*c;

	ret = 0;
	while (s[ret] != '\0')
	{
		c = accept;
		while (*c != '\0')
		{
			if (s[ret] != *c && *c != '\0')
				c++;
			if (*c == '\0')
				return (ret);
			if (s[ret] == *c)
				break ;
		}
		ret++;
	}
	return (ret);
}
