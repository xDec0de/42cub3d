/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:28 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:07:12 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static void	add_alloc(void *ptr)
{
	t_alloc_node	*lst;
	t_alloc_node	*new;

	lst = get_alloc_list();
	if (ptr == NULL)
		return ;
	new = __real_malloc(sizeof(t_alloc_node));
	new->ptr = ptr;
	new->next = NULL;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}

void	*__wrap_malloc(size_t size)
{
	void	*ptr;

	ptr = __real_malloc(size);
	add_alloc(ptr);
	return (ptr);
}
