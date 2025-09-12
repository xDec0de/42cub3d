/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 06:08:29 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 06:18:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_types.h"
#include "cb_strutils.h"

bool	cb_strendswith(char *str, char *suffix)
{
	size_t	suf_i;
	size_t	str_i;

	if (str == NULL || suffix == NULL)
		return (false);
	suf_i = cb_strlen(suffix);
	str_i = cb_strlen(str);
	if (suf_i > str_i)
		return (false);
	while (suf_i != 0)
	{
		suf_i--;
		str_i--;
		if (str[str_i] != suffix[suf_i])
			return (false);
	}
	return (true);
}
