/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:45:59 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/02 17:50:35 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_types.h"

/* TEMP: hardcoded wall textures until real asset parser is implemented */

void	parse_assets(t_game *game, char **map_data)
{
	(void) map_data;
	game->map.no_path = cb_strdup("./textures/north.xpm");
	game->map.so_path = cb_strdup("./textures/south.xpm");
	game->map.we_path = cb_strdup("./textures/west.xpm");
	game->map.ea_path = cb_strdup("./textures/east.xpm");
}
