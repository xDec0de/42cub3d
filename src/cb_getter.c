/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:15:50 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/01 17:21:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_mem.h"
#include "cb_render.h"

static t_player	init_player(void)
{
	t_player	player;

	player.angle = PI / 2;
	player.x = 0;
	player.y = 0;
	player.key_up = false;
	player.key_down = false;
	player.key_right = false;
	player.key_left = false;
	player.right_rotate = false;
	player.left_rotate = false;
	return (player);
}

static t_map	init_map(void)
{
	t_map	map;

	map.grid = NULL;
	map.ceil_col.r = 0;
	map.ceil_col.g = 0;
	map.ceil_col.b = 0;
	map.floor_col.r = 0;
	map.floor_col.g = 0;
	map.floor_col.b = 0;
	return (map);
}

static t_assets	init_assets(void)
{
	t_assets	assets;

	assets.north = NULL;
	assets.south = NULL;
	assets.west = NULL;
	assets.east = NULL;
	return (assets);
}

static t_game	*cb_init(void)
{
	t_game	*game;

	game = cb_malloc(sizeof(t_game));
	game->mlx = NULL;
	game->window = NULL;
	game->img = NULL;
	game->map = init_map();
	game->player = init_player();
	game->assets = init_assets();
	return (game);
}

t_game	*cb_get(void)
{
	static t_game	*game = NULL;

	if (game == NULL)
		game = cb_init();
	return (game);
}
