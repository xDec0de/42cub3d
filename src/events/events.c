/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:22:24 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/21 17:30:23 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_events.h"

int	close_window(void)
{
	fake_cb_exit(NULL, 0);
	return (0);
}

int	handle_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window();
	(void)game;
	return (0);
}
