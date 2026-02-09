/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:37:37 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/09 00:01:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_STRUTILS_H
# define CB_STRUTILS_H

# include "cb_types.h"

char	**cb_split(const char *s, char c);

char	*cb_strdup(const char *str);

bool	cb_strendswith(const char *str, const char *suffix);

bool	cb_strhasch(const char *str, const char ch);

char	*cb_strjoin(char *s1, char *s2);

size_t	cb_strlen(const char *str);

bool	cb_strstartswith(const char *str, const char *prefix);

#endif
