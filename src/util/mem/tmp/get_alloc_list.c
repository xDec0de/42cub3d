/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:31:49 by daniema3          #+#    #+#             */
/*   Updated: 2025/08/17 19:32:03 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

t_alloc_node	*get_alloc_list(t_alloc_node *first)
{
	static t_alloc_node	*alloc_list = NULL;

	if (first != NULL)
		alloc_list = first;
	return (alloc_list);
}
