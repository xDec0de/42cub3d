/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_strutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:37:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 06:19:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_STRUTILS_H
# define CB_STRUTILS_H

# include "cb_types.h"

size_t	cb_strlen(char *str);
bool	cb_strendswith(char *str, char *suffix);

#endif
