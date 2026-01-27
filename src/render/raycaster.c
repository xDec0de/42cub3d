/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:19:14 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 18:07:02 by rexposit         ###   ########.fr       */
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

void	raycaster(t_game *game)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	ray_x = game->player.x;
	ray_y = game->player.y;
	get_angle_vectors(&game->player, &cos_angle, &sin_angle);
	while (!touch(ray_x, ray_y, game))
	{
		my_mlx_pixel_put(&game->data, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}
