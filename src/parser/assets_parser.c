/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:45:59 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/13 00:00:00 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parser.h"

static void	parse_asset_line(t_map *map, char *line)
{
	if (cb_strstartswith(line, "NO ") && !map->no_path)
		map->no_path = cb_strdup(line + 3);
	else if (cb_strstartswith(line, "SO ") && !map->so_path)
		map->so_path = cb_strdup(line + 3);
	else if (cb_strstartswith(line, "WE ") && !map->we_path)
		map->we_path = cb_strdup(line + 3);
	else if (cb_strstartswith(line, "EA ") && !map->ea_path)
		map->ea_path = cb_strdup(line + 3);
}

void	parse_assets(t_game *game, char **map_data)
{
	size_t	i;

	i = 0;
	while (map_data[i] != NULL && !is_map_line(map_data[i]))
	{
		parse_asset_line(&game->map, map_data[i]);
		i++;
	}
	if (!game->map.no_path || !game->map.so_path
		|| !game->map.we_path || !game->map.ea_path)
	{
		cb_arrfree((void **) map_data);
		cb_exit(ERR_MISSING_TEXTURE, ERRC_MISSING_TEXTURE);
	}
}
