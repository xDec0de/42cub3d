/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:54:41 by rexposit          #+#    #+#             */
/*   Updated: 2025/09/12 13:37:27 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cb_types.h"

t_game	*cb_store(t_game *init)
{
	static t_game	*game = NULL;

	if (init != NULL)
		game = init;
	return (game);
}

t_game	*cb_get(void)
{
	return (cb_store(NULL));
}

t_game	*cb_init(void)
{
	t_game	*init;

	init = cb_malloc(sizeof(t_game));
	if (!init)
		return (NULL);
	init->map.grid = NULL;
	init->map.width = 0;
	init->map.height = 0;
	init->map.ceil_col.r = 0;
	init->map.ceil_col.g = 0;
	init->map.ceil_col.b = 0;
	init->map.floor_col.r = 0;
	init->map.floor_col.g = 0;
	init->map.floor_col.b = 0;
	init->player.x = 0;
	init->player.y = 0;
	init->player.dir = 0;
	return (cb_store(init));
}
