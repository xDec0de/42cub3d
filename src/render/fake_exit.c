/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:51:24 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/15 20:53:27 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "cb_strutils.h"
#include "cb_render.h"

void	fake_free_game(t_game *game)
{
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

void	fake_cb_exitf(int print_res, int ec)
{
	t_game	*game;

	(void) print_res;
	game = fake_cb_get();
	if (game != NULL)
		fake_free_game(game);
	exit(ec);
}

void	fake_cb_exit(char *msg, int ec)
{
	if (msg != NULL)
		fake_cb_exitf(write(STDOUT_FILENO, msg, cb_strlen(msg)), ec);
	else
		fake_cb_exitf(0, ec);
}
