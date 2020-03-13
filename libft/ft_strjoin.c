/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:32:24 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/25 07:08:13 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;

	if (!s1 || !s2)
		return (NULL);
	if ((dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ft_strcat(ft_strcpy(dst, s1), s2);
	return (dst);
}
