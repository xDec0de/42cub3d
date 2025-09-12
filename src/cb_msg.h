/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_msg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:32:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 04:49:00 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_MSG_H
# define CB_MSG_H

void	cb_exit(char *msg, int ec);

/** Error: Invalid argument count */
# define ERR_ARGC "\e[0;31mUsage\e[1;30m: \e[1;31m%s [map.cub]\033[0m\n"
/** Error code: Invalid argument count */
# define ERRC_ARGC 1

/** Error: Invalid argument count */
# define ERR_MALLOC_FAIL "\e[0;31mError\e[1;30m: \e[1;31mMalloc failed\033[0m\n"
/** Error code: Invalid argument count */
# define ERRC_MALLOC_FAIL 2

#endif