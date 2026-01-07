/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:08:04 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/07 09:21:55 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_player	init_player(void)
{
	t_player	player;

	player.dir = 'E';
	player.x = 1;
	player.y = 2;
	return (player);
}

t_map	init_map(void)
{
	t_map	map;

	map.grid = (char *[])
	{
		"11111",
		"10001",
		"1E001",
		"10001",
		"11111",
		NULL
	};
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
	game->map = init_map();
	game->player = init_player();
	return (game);
}

t_game	*fake_cb_get(void)
{
	static t_game	*game = NULL;

	if (game == NULL)
		game = fake_cb_init();
	return (game);
}