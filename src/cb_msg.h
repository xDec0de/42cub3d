/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_msg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:32:48 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/09 00:05:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_MSG_H
# define CB_MSG_H

# include <stdio.h>

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

# define ERR_INVALID_COLOR "\e[0;31mError\e[1;30m: \e[1;31mInvalid\
 color format \e[1;30m- \e[1;31m%s\033[0m\n"
# define ERRC_INVALID_COLOR 4

/*
 - Internal errors
 */

/** Internal error: Malloc failed */
# define ERR_MALLOC_FAIL "\e[0;31mError\e[1;30m: \e[1;31mMalloc failed\033[0m\n"
/** Internal error code: Malloc failed */
# define ERRC_MALLOC_FAIL -1

/** Internal error: Read failed */
# define ERR_READ_FAIL "\e[0;31mError\e[1;30m: \e[1;31mRead failed\
 \e[1;30m- \e[1;31m%s\033[0m\n"
/** Internal error code: Read failed */
# define ERRC_READ_FAIL -2

/** Internal error: MLX init failed */
# define ERR_MLX_INIT_FAIL "\e[0;31mError\e[1;30m: \e[1;31mMLX init\
 failed\033[0m\n"
/** Internal error code: MLX init failed */
# define ERRC_MLX_INIT_FAIL -3

/** Internal error: Window init failed */
# define ERR_WINDOW_INIT_FAIL "\e[0;31mError\e[1;30m: \e[1;31mWindow init\
 failed\033[0m\n"
/** Internal error code: Window init failed */
# define ERRC_WINDOW_INIT_FAIL -4

/** Internal error: Image creation failed */
# define ERR_IMG_CREATION_FAIL "\e[0;31mError\e[1;30m: \e[1;31mImage creation\
 failed\033[0m\n"
/** Internal error code: Image creation failed */
# define ERRC_IMG_CREATION_FAIL -5

#endif