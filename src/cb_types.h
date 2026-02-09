/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:18:46 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/09 01:54:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_TYPES_H
# define CB_TYPES_H

# include <stdbool.h>
# include <stddef.h>

# define DEBUG false

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
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_right;
	bool	key_left;
	bool	right_rotate;
	bool	left_rotate;
}	t_player;

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_assets
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_assets;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img;
	t_map		map;
	t_player	player;
	t_data		data;
	t_assets	assets;
}	t_game;

t_game	*cb_get(void);

#endif
