/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:08:51 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:24:33 by daniema3         ###   ########.fr       */
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

t_alloc_node	*get_alloc_list(void);

# define LEAKS_FOUND "❌ \e[1;31mRemoved \e[1;33m%u \e[1;31m\
memory leak(s)\033[0m\n"
# define NO_LEAKS_FOUND "✅ \e[1;32mNo memory leaks found\033[0m\n"

#endif
