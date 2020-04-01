/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:15:27 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 20:35:37 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
