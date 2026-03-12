/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:49:44 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/09 12:09:55 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

void
	draw_ceiling_and_floor(t_game *game, int x, int wall_start, int wall_end)
{
	int	y;

	if (wall_start < 0)
		wall_start = 0;
	if (wall_end > WINDOW_HEIGHT)
		wall_end = WINDOW_HEIGHT;
	y = 0;
	while (y < wall_start)
	{
		my_mlx_pixel_put_color(&game->data, x, y, game->map.ceil_col);
		y++;
	}
	y = wall_end;
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put_color(&game->data, x, y, game->map.floor_col);
		y++;
	}
}

void	draw_square(int x, int y, int size, int color)
{
	t_game	*game;
	int		i;

	game = cb_get();
	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(&game->data, x + i, y, color);
		my_mlx_pixel_put(&game->data, x, y + i, color);
		my_mlx_pixel_put(&game->data, x + size, y + i, color);
		my_mlx_pixel_put(&game->data, x + i, y + size, color);
		i++;
	}
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y] != NULL)
	{
		x = 0;
		while (map->grid[y][x] != '\0')
		{
			if (map->grid[y][x] == '1')
				draw_square(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0x0000FF);
			x++;
		}
		y++;
	}
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&game->data, x, y, 0);
			x++;
		}
		y++;
	}
}
