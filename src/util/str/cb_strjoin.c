/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:54:48 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/08 23:30:47 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_strutils.h"
#include "cb_mem.h"

char	*cb_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = cb_malloc((cb_strlen(s1) + cb_strlen(s2) + 1) * sizeof(char));
	if (str != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i + j] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
	}
	free(s1);
	return (str);
}
