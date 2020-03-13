/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:16:00 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 06:55:20 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **item, void (*del)(void *, size_t))
{
	if (!item || !*item || !del)
		return ;
	del((*item)->content, (*item)->content_size);
	ft_memdel((void **)item);
}
