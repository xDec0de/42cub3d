/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:31:49 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:15:40 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

t_alloc_node	*init_alloc_list(void)
{
	t_alloc_node	*list;

	list = __real_malloc(sizeof(t_alloc_node));
	list->ptr = NULL;
	list->next = NULL;
	return (list);
}

t_alloc_node	*get_alloc_list(void)
{
	static t_alloc_node	*alloc_list = NULL;

	if (alloc_list == NULL)
		alloc_list = init_alloc_list();
	return (alloc_list);
}
