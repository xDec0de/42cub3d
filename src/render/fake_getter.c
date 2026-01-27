/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:08:04 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 11:38:28 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"
#include "cb_mem.h"

t_player	fake_init_player(void)
{
	t_player	player;

	player.dir = 'E';
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.key_up = false;
	player.key_down = false;
	player.key_right = false;
	player.key_left = false;
	return (player);
}

t_map	fake_init_map(void)
{
	t_map		map;
	static char	*grid[11];

	grid[0] = "1111111111111111";
	grid[1] = "1000000000000001";
	grid[2] = "1E00000000000001";
	grid[3] = "1000000000000001";
	grid[4] = "1000000000000001";
	grid[5] = "1000000000000001";
	grid[6] = "1000000000000001";
	grid[7] = "1000000000000001";
	grid[8] = "1000000000000001";
	grid[9] = "1111111111111111";
	grid[10] = NULL;
	map.grid = grid;
	map.ceil_col.r = 255;
	map.ceil_col.g = 0;
	map.ceil_col.b = 0;
	map.floor_col.r = 0;
	map.floor_col.g = 0;
	map.floor_col.b = 255;
	return (map);
}

t_game	*fake_cb_init(void)
{
	t_game	*game;

	game = cb_malloc(sizeof(t_game));
	game->map = fake_init_map();
	game->player = fake_init_player();
	return (game);
}

t_game	*fake_cb_get(void)
{
	static t_game	*game = NULL;

	if (game == NULL)
		game = fake_cb_init();
	return (game);
}
