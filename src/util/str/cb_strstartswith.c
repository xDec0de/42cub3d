/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:15:17 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/08 19:21:33 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_strutils.h"

bool	cb_strstartswith(const char *str, const char *prefix)
{
	size_t	i;
	size_t	pre_len;

	i = 0;
	pre_len = cb_strlen(prefix);
	if (pre_len == 0)
		return (true);
	while (str[i] != '\0' && i < pre_len)
	{
		if (str[i] != prefix[i])
			return (false);
		i++;
	}
	return (i == pre_len);
}
