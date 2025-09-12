/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:18:08 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 04:49:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cb_msg.h"

void	*cb_malloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		cb_exit(ERR_MALLOC_FAIL, ERRC_MALLOC_FAIL);
	return (ptr);
}
