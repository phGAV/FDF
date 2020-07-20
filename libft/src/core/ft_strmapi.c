/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:27:10 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 22:08:03 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n;
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(n = ft_strnew(ft_strlen(s))))
		return (NULL);
	ret = n;
	while (*s != '\0')
		*n++ = f(i++, *s++);
	return (ret);
}
