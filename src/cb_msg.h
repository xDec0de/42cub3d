/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_msg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:32:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 13:30:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_MSG_H
# define CB_MSG_H

void	cb_exitf(int print_res, int ec);
void	cb_exit(char *msg, int ec);

/*
 - User errors
 */

/** User error: Invalid argument count */
# define ERR_ARGC "\e[0;31mUsage\e[1;30m: \e[1;31m%s [map.cub]\033[0m\n"
/** User error code: Invalid argument count */
# define ERRC_ARGC 1

/** User error: Provided map file name doesn't end with '.cub' */
# define ERR_MAP_FILE_EXTENSION "\e[0;31mError\e[1;30m: \e[1;31mInvalid map\
 file extension. Map files must have the '.cub' extension\033[0m\n"
/** User error code: Provided map file name doesn't end with '.cub' */
# define ERRC_MAP_FILE_EXTENSION 2

# define ERR_OPEN_MAP "\e[0;31mError\e[1;30m: \e[1;31mCould\
 not open map file \e[1;30m- \e[1;31m%s\033[0m\n"
# define ERRC_OPEN_MAP 3

/*
 - Internal errors
 */

/** Internal error: Malloc failed */
# define ERR_MALLOC_FAIL "\e[0;31mError\e[1;30m: \e[1;31mMalloc failed\033[0m\n"
/** Internal error code: Malloc failed */
# define ERRC_MALLOC_FAIL -1

#endif