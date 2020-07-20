/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diona <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:49:44 by diona             #+#    #+#             */
/*   Updated: 2019/10/10 22:19:36 by diona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_list(t_list **head, int fd)
{
	t_list	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->content_size == (size_t)fd)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = ft_lstnew("", fd)))
		return (NULL);
	ft_lstadd(head, lst);
	return (lst);
}

int		tail_to_line(char **tail, char **line)
{
	char	*pos;
	char	*tmp;
	int		ret;

	tmp = *tail;
	ret = 0;
	if ((pos = ft_strchr(*tail, '\n')))
	{
		*line = ft_strsub(*tail, 0, pos - *tail);
		*tail = ft_strdup(++pos);
		ret = 1;
	}
	else
	{
		*line = ft_strdup(*tail);
		*tail = ft_strnew(0);
	}
	free(tmp);
	return (ret);
}

int		go_read_smth(char **tail, int fd)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *tail;
		*tail = ft_strjoin(*tail, buf);
		free(tmp);
		if (ft_strchr(*tail, '\n'))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int				result;
	int				ret;
	char			*tail;
	static t_list	*head;
	t_list			*lst;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 ||
			!(lst = find_list(&head, fd)))
		return (-1);
	tail = lst->content;
	if ((result = go_read_smth(&tail, fd)) < 0)
		return (-1);
	ret = tail_to_line(&tail, line);
	lst->content = tail;
	if (!*tail && !result && !**line && !ret)
		return (0);
	return (1);
}
