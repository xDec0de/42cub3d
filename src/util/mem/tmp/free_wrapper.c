/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:34:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:22:35 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdbool.h>
#include <stdio.h>

void	remove_alloc(void *ptr)
{
	t_alloc_node	*current;
	t_alloc_node	*prev;

	current = get_alloc_list()->next;
	prev = get_alloc_list();
	while (current != NULL)
	{
		if (current->ptr == ptr)
		{
			prev->next = current->next;
			__real_free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
	printf("FREE TO UNKNOWN POINTER\n");
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
	int				leaks;

	current = get_alloc_list()->next;
	leaks = 0;
	while (current != NULL)
	{
		__real_free(current->ptr);
		tmp = current;
		leaks++;
		current = current->next;
		__real_free(tmp);
	}
	if (leaks != 0)
		printf(LEAKS_FOUND, leaks);
	else
		printf(NO_LEAKS_FOUND);
	__real_free(get_alloc_list());
}
