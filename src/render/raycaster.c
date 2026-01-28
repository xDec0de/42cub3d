/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:19:14 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/28 23:21:39 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static bool	ray_hits_wall(float px, float py, t_game *game)
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

static float	distance(float x, float y)
{
	return (sqrtf(x * x + y * y));
}

static float	fixed_dist(float x1, float y1, float x2, float y2)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	t_game	*game;

	game = fake_cb_get();
	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	return (distance(delta_x, delta_y) * cos(angle));
}

static void	cast_ray(t_game *game, float ray_angle, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(ray_angle);
	sin_angle = sin(ray_angle);
	ray_x = game->player.x;
	ray_y = game->player.y;
	while (!ray_hits_wall(ray_x, ray_y, game))
	{
		if (DEBUG)
			my_mlx_pixel_put(&game->data, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
		draw_wall_slice(game, fixed_dist(game->player.x,
				game->player.y, ray_x, ray_y), i);
}

void	raycaster(t_game *game)
{
	float	angle_step;
	float	ray_angle;
	int		i;

	angle_step = PI / 3 / WINDOW_WIDTH;
	ray_angle = game->player.angle - PI / 6;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		cast_ray(game, ray_angle, i);
		ray_angle += angle_step;
		i++;
	}
}
