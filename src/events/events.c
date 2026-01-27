/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:22:24 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 11:07:23 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_events.h"

int	close_window(void)
{
	fake_cb_exit(NULL, 0);
	return (0);
}

void	move_player(t_player *player, int speed)
{
	if (player->key_up)
		player->y -= speed;
	if (player->key_down)
		player->y += speed;
	if (player->key_right)
		player->x += speed;
	if (player->key_left)
		player->x -= speed;
}
