/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:35:45 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 20:20:09 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n;
	char	*ret;

	if (!s)
		return (NULL);
	if (!(n = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret = n;
	while (*s != '\0')
	{
		*n = f(*s);
		n++;
		s++;
	}
	return (ret);
}
