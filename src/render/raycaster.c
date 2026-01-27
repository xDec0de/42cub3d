/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:19:14 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 23:24:25 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / TILE_SIZE;
	y = py / TILE_SIZE;
	if (x >= game->map.width || y >= game->map.height || x < 0 || y < 0)
		return (true);
	if (game->map.grid[y][x] == '1')
		return (true);
	else
		return (false);
}

void	draw_line(t_game *game, float start_x)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = game->player.x;
	ray_y = game->player.y;
	while (!touch(ray_x, ray_y, game))
	{
		my_mlx_pixel_put(&game->data, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

void	raycaster(t_game *game)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WINDOW_WIDTH;
	start_x = game->player.angle - PI / 6;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		draw_line(game, start_x);
		start_x += fraction;
		i++;
	}
}
