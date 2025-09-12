/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:28 by daniema3          #+#    #+#             */
/*   Updated: 2025/08/17 19:33:23 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static void	add_alloc(void *ptr)
{
	t_alloc_node	*first;
	t_alloc_node	*new;

	first = get_alloc_list(NULL);
	if (ptr == NULL)
		return ;
	new = __real_malloc(sizeof(t_alloc_node));
	new->ptr = ptr;
	new->next = first;
	get_alloc_list(new);
}

void	*__wrap_malloc(size_t size)
{
	void	*ptr;

	ptr = __real_malloc(size);
	add_alloc(ptr);
	return (ptr);
}
