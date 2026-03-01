/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:55:34 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/01 16:18:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parser.h"
#include <stdio.h>

char	**clone_array(char **arr, size_t from)
{
	char	**clone;
	size_t	size;
	size_t	clone_i;

	size = 0;
	clone_i = 0;
	while (arr[from + size] != NULL)
		size++;
	clone = cb_malloc((size + 1) * sizeof(char *));
	while (arr[from] != NULL)
	{
		clone[clone_i] = cb_strdup(arr[from]);
		from++;
		clone_i++;
	}
	clone[clone_i] = NULL;
	return (clone);
}

bool	extract_map_grid(t_game *game, char **map_data)
{
	size_t	i;

	i = 0;
	while (map_data[i] != NULL)
	{
		if (is_map_line(map_data[i]))
			break ;
		i++;
	}
	if (map_data[i] == NULL)
		return (false);
	game->map.grid = clone_array(map_data, i);
	return (true);
}

void	parse_map_file(t_game *game, char **map_data)
{
	parse_assets(game, map_data);
	parse_colors(game, map_data);
	extract_map_grid(game, map_data);
	validate_structure(game->map.grid, map_data);
	find_player_pos(game);
	game->map.height = 10;
	game->map.width = 16;
}
