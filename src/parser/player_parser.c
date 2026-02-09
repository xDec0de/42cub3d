/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 01:39:50 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/09 02:05:55 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parser.h"
#include "cb_render.h"

static void	update_player_pos(t_game *game, int x, int y, char ch)
{
	game->player.x = x * TILE_SIZE;
	game->player.y = y * TILE_SIZE;
	if (ch == 'E')
		game->player.angle = 0;
	if (ch == 'N')
		game->player.angle = PI / 2;
	if (ch == 'W')
		game->player.angle = PI;
	if (ch == 'S')
		game->player.angle = 3 * PI / 2;
}

void	find_player_pos(t_game *game)
{
	char	**grid;
	int		x;
	int		y;
	char	ch;

	grid = game->map.grid;
	y = 0;
	while (grid[y] != NULL)
	{
		x = 0;
		while (grid[y][x] != '\0')
		{
			ch = grid[y][x];
			if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
			{
				update_player_pos(game, x, y, ch);
				break ;
			}
			x++;
		}
		y++;
	}
}
