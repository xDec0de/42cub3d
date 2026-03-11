/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:34:46 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/11 15:47:54 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "cb_strutils.h"
#include "cb_mem.h"

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.north.img);
	mlx_destroy_image(game->mlx, game->assets.south.img);
	mlx_destroy_image(game->mlx, game->assets.west.img);
	mlx_destroy_image(game->mlx, game->assets.east.img);
	mlx_destroy_image(game->mlx, game->img);
	if (game->map.grid != NULL)
		cb_arrfree((void **) game->map.grid);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game->map.no_path);
	free(game->map.so_path);
	free(game->map.we_path);
	free(game->map.ea_path);
	free(game);
}

void	cb_exitf(int print_res, int ec)
{
	t_game	*game;

	(void) print_res;
	game = cb_get();
	if (game != NULL)
		free_game(game);
	exit(ec);
}

void	cb_exit(char *msg, int ec)
{
	if (msg != NULL)
		cb_exitf(write(STDOUT_FILENO, msg, cb_strlen(msg)), ec);
	else
		cb_exitf(0, ec);
}
