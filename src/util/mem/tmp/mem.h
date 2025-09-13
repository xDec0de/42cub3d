/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:08:51 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 09:17:42 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <unistd.h>

typedef struct s_alloc_node
{
	void				*ptr;
	struct s_alloc_node	*next;
}			t_alloc_node;

void			*__real_malloc(size_t size);
void			__real_free(void *ptr);

t_alloc_node	*get_alloc_list(t_alloc_node *first);

void			*cb_malloc(size_t size);

#endif
