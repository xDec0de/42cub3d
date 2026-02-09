/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:16:04 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/08 22:29:25 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_strutils.h"
#include "cb_mem.h"

char	*cb_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = cb_strlen(str);
	dup = cb_malloc((len + 1) * sizeof(char));
	dup[len] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
