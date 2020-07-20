/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <sys/types.h>
# include <stdbool.h>
# include <stddef.h>

# define ENOINDEX -1

typedef void *	t_obj;

typedef struct {
	size_t	item_size;
	ssize_t	size;
	ssize_t	max_size;
	void	*data;
	t_obj	none;
	void	(*ctor)(void *, const void *);
	void	(*dtor)(void *);
}	t_vec;

t_vec		vectorize(void *data, size_t size, size_t item_size);

t_vec		*vec_create(size_t size, size_t item_size);
t_vec		*vec_import(const char *s, int delim, size_t item_size,
				void (*f)(void *, const char *, const char *));
t_vec		*vec_clone(const t_vec *v);
void		vec_copy(t_vec *v, const t_vec *u);
void		vec_clear(t_vec *v);
void		vec_free(t_vec *v);

void		vec_apply(t_vec *v, void (*f)(void *));
t_vec		*vec_filter(const t_vec *v, bool (*f)(const void *));
t_vec		*vec_map(const t_vec *v, void (*f)(void *));
void		vec_sort(t_vec *v, int (*cmp)(const void *, const void *));
void		vec_reverse(t_vec *v);
t_vec		*vec_extend(t_vec *v, const t_vec *u);
t_vec		*vec_extract(const t_vec *v, ssize_t index, size_t size);

void		*vec_search(const t_vec *v, const void *object);
void		*vec_bsearch(const t_vec *v, const void *object,
				int (*cmp)(const void *, const void *));
ssize_t		vec_index(const t_vec *v, const void *object);
size_t		vec_count(const t_vec *v, const void *object);
void		*vec_append(t_vec *v, const void *object);
void		*vec_insert(t_vec *v, ssize_t index, const void *object);
void		*vec_set(t_vec *v, ssize_t index, const void *object);
void		*vec_get(const t_vec *v, ssize_t index);
void		*vec_pop(t_vec *v, ssize_t index);
void		*vec_remove(t_vec *v, ssize_t index);

#endif
