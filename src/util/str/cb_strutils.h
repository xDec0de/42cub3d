/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:37:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 17:02:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_STRUTILS_H
# define CB_STRUTILS_H

# include "cb_types.h"

char	**cb_split(const char *s, char c);
size_t	cb_strlen(char *str);
bool	cb_strendswith(char *str, char *suffix);

#endif
