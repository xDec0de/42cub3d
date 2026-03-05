/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:19:14 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/05 21:21:27 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static void	cast_ray(t_game *game, float ray_angle, int i)
{
	t_ray	ray;

	raycast_build_ray(game, &ray, ray_angle, i);
	if (!DEBUG)
		draw_wall_slice(game, ray.dist, i, ray);
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
