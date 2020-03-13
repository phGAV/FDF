/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:02:25 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/28 16:41:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *item;

	if ((item = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
			if ((item->content = ft_memalloc(content_size)))
				ft_memcpy(item->content, content, content_size);
			else
				return (NULL);
		else
			item->content = NULL;
		item->content_size = item->content ? content_size : 0;
		item->next = NULL;
	}
	return (item);
}
