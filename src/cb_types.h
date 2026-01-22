/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:18:46 by daniema3          #+#    #+#             */
/*   Updated: 2026/01/22 12:11:46 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_TYPES_H
# define CB_TYPES_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	t_color	ceil_col;
	t_color	floor_col;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct t_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img;
	t_map		map;
	t_player	player;
	t_data		data;
}	t_game;

t_game	*cb_get(void);

#endif
