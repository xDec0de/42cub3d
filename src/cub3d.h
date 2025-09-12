/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 04:29:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cb_types.h"

# include <stdlib.h>

# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
}	t_game;

/** Error: Invalid argument count */
# define ERR_ARGC "\e[0;31mUsage\e[1;30m: \e[1;31m%s [map.cub]\033[0m\n"
/** Error code: Invalid argument count */
# define ERRC_ARGC 1

#endif