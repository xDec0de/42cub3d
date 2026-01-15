/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:07:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/15 21:59:36 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"
#include <stdio.h>

void	render(void)
{
	t_game	*game;

	game = fake_cb_get();
	game->mlx = mlx_init();
	if (!game->mlx)
		fake_cb_exit(NULL, -3);
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game->window)
		fake_cb_exit(NULL, -3);
	mlx_loop(game->mlx);
	fake_cb_exit(NULL, 0);
}
