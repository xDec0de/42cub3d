/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:34:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/08/17 19:35:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	remove_alloc(void *ptr)
{
	t_alloc_node	*current;
	t_alloc_node	*prev;

	current = get_alloc_list(NULL);
	prev = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				get_alloc_list(current->next);
			__real_free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	__wrap_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	remove_alloc(ptr);
	__real_free(ptr);
}

__attribute__((destructor))
void	mem_destructor(void)
{
	t_alloc_node	*current;
	t_alloc_node	*tmp;

	current = get_alloc_list(NULL);
	while (current != NULL)
	{
		__real_free(current->ptr);
		tmp = current;
		current = current->next;
		__real_free(tmp);
	}
}
