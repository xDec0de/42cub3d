/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:07:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/21 17:35:46 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

void	render(void)
{
	t_game	*game;

	game = fake_cb_get();
	game->mlx = mlx_init();
	if (!game->mlx)
		fake_cb_exit(NULL, ERRC_MLX_INIT_FAIL);
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	if (!game->window)
		fake_cb_exit(NULL, ERRC_WINDOW_INIT_FAIL);
	mlx_hook(game->window, 17, 0L, close_window, game);
	mlx_key_hook(game->window, handle_key, game);
	mlx_loop(game->mlx);
}
