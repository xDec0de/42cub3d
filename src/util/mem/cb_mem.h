/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:18:03 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/08 23:31:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_MEM_H
# define CB_MEM_H

# include "cb_types.h"
# include <stdlib.h>

void	cb_arrfree(void **arr);
void	*cb_malloc(size_t size);

#endif
