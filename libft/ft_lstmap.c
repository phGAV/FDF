/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:46:15 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/25 08:00:17 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_kill_me_plenty(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *item))
{
	t_list *head;

	if (!lst || !f)
		return (NULL);
	if (!(head = f(lst)))
		return (NULL);
	while ((lst = lst->next))
		if (!ft_lstaddlast(&head, f(lst)))
		{
			ft_lstdel(&head, &ft_kill_me_plenty);
			return (NULL);
		}
	return (head);
}
