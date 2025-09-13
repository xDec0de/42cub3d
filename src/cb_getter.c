/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:15:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 09:29:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_mem.h"

t_player	init_player(void)
{
	t_player	player;

	player.dir = '\0';
	player.x = 0;
	player.y = 0;
	return (player);
}

t_map	init_map(void)
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

t_game	*cb_init(void)
{
	t_game	*game;

	game = cb_malloc(sizeof(t_game));
	game->map = init_map();
	game->player = init_player();
	return (game);
}

t_game	*cb_get(void)
{
	static t_game *game = NULL;

	if (game == NULL)
		game = cb_init();
	return (game);
}
