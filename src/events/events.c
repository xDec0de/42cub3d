/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:22:24 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 13:42:28 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_events.h"

int	close_window(void)
{
	fake_cb_exit(NULL, 0);
	return (0);
}

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

static	void	get_angle_vectors(t_player *player, float *cos_a, float *sin_a)
{
	*cos_a = cos(player->angle);
	*sin_a = sin(player->angle);
}

void	move_player(t_player *player, int speed, float angle_speed)
{
	float	cos_angle;
	float	sin_angle;

	update_player_angle(player, angle_speed);
	get_angle_vectors(player, &cos_angle, &sin_angle);
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
	if (player->key_left)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
}
