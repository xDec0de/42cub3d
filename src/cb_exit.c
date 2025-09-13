/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:34:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:46:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "cb_strutils.h"

void	free_game(t_game *game)
{
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
