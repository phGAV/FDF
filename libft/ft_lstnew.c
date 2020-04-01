/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:25:01 by diona             #+#    #+#             */
/*   Updated: 2019/09/30 22:00:58 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	if (!(lst->content = ft_memalloc(content_size)))
	{
		free(lst);
		return (NULL);
	}
	lst->content = ft_memmove(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
