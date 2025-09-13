/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:34:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 10:09:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "cb_strutils.h"

void	free_game(t_game *game)
{
	free(game);
}

void	cb_exit(char *msg, int ec)
{
	t_game	*game;

	game = cb_get();
	if (msg != NULL)
		write(STDOUT_FILENO, msg, cb_strlen(msg));
	if (game != NULL)
		free_game(game);
	exit(ec);
}
