/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:06:24 by diona             #+#    #+#             */
/*   Updated: 2019/09/21 17:34:34 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *data, size_t size)
{
	ft_memdel(&data);
	size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	ret = new;
	while ((lst = lst->next))
	{
		if (!(tmp = f(lst)))
		{
			ft_lstdel(&ret, ft_del);
			return (NULL);
		}
		new->next = tmp;
		new = new->next;
	}
	return (ret);
}
