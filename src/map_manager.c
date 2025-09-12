/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:54:41 by rexposit          #+#    #+#             */
/*   Updated: 2025/09/12 14:12:51 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_types.h"

t_game	*cb_init(void)
{
	static t_game	game;

	game.map.grid = NULL;
	game.map.width = 0;
	game.map.height = 0;
	game.map.ceil_col.r = 0;
	game.map.ceil_col.g = 0;
	game.map.ceil_col.b = 0;
	game.map.floor_col.r = 0;
	game.map.floor_col.g = 0;
	game.map.floor_col.b = 0;
	game.player.x = 0;
	game.player.y = 0;
	game.player.dir = 0;
	return (&game);
}

t_game	*cb_get(void)
{
	return (cb_init());
}
