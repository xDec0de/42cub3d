/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:22:24 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/29 22:07:39 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_events.h"

static	void	update_player_angle(t_player *player, float angle_speed)
{
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void
	move_player_safely(t_player *player, float dx, float dy, char **grid)
{
	int	rx;
	int	ry;

	rx = (int)((player->x + dx) / TILE_SIZE);
	ry = (int)(player->y / TILE_SIZE);
	if (grid[ry][rx] != '1')
		player->x += dx;
	rx = (int)(player->x / TILE_SIZE);
	ry = (int)((player->y + dy) / TILE_SIZE);
	if (grid[ry][rx] != '1')
		player->y += dy;
}

static float	get_new_x(t_player *player, float cos_a, float sin_a, int speed)
{
	float	new_x;

	new_x = 0;
	if (player->key_up)
		new_x += cos_a * speed;
	if (player->key_down)
		new_x -= cos_a * speed;
	if (player->key_right)
		new_x -= sin_a * speed;
	if (player->key_left)
		new_x += sin_a * speed;
	return (new_x);
}

static float	get_new_y(t_player *player, float cos_a, float sin_a, int speed)
{
	float	new_y;

	new_y = 0;
	if (player->key_up)
		new_y += sin_a * speed;
	if (player->key_down)
		new_y -= sin_a * speed;
	if (player->key_right)
		new_y += cos_a * speed;
	if (player->key_left)
		new_y -= cos_a * speed;
	return (new_y);
}

void	move_player(t_player *player, int speed, float angle_speed, char **grid)
{
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;

	update_player_angle(player, angle_speed);
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	new_x = get_new_x(player, cos_angle, sin_angle, speed);
	new_y = get_new_y(player, cos_angle, sin_angle, speed);
	move_player_safely(player, new_x, new_y, grid);
}
