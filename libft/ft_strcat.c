/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:43:57 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 14:05:26 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*c;

	c = s1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (*c != '\0')
		c++;
	while (*s2 != '\0')
		*c++ = *s2++;
	*c = '\0';
	return (s1);
}
