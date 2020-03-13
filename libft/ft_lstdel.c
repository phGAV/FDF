/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:32:19 by ourgot            #+#    #+#             */
/*   Updated: 2019/09/27 01:20:11 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **head, void (*del)(void *, size_t))
{
	if (!head || !*head || !del)
		return ;
	if ((*head)->next)
		ft_lstdel(&(*head)->next, del);
	ft_lstdelone(head, del);
}
