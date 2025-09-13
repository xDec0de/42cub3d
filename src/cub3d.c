/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 12:45:45 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "cb_msg.h"
#include "cb_strutils.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		cb_exitf(printf(ERR_ARGC, argv[0]), ERRC_ARGC);
	if (!cb_strendswith(argv[1], ".cub"))
		cb_exit(ERR_MAP_FILE_EXTENSION, ERRC_MAP_FILE_EXTENSION);
	game = cb_get();
	(void) game;
	cb_exit(NULL, EXIT_SUCCESS);
}
