/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:07:56 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 01:43:02 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_events.h"

int	key_press(int key, t_player *player)
{
	if (key == KEY_W)
		player->key_up = true;
	if (key == KEY_S)
		player->key_down = true;
	if (key == KEY_D)
		player->key_right = true;
	if (key == KEY_A)
		player->key_left = true;
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == KEY_W)
		player->key_up = false;
	if (key == KEY_S)
		player->key_down = false;
	if (key == KEY_D)
		player->key_right = false;
	if (key == KEY_A)
		player->key_left = false;
	return (0);
}
