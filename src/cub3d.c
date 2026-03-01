/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:27 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/01 17:20:42 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "cb_strutils.h"
#include "cb_mem.h"
#include "cb_render.h"
#include "cb_parser.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map_data;

	if (argc != 2)
		cb_exitf(printf(ERR_ARGC, argv[0]), ERRC_ARGC);
	if (!cb_strendswith(argv[1], ".cub"))
		cb_exit(ERR_MAP_FILE_EXTENSION, ERRC_MAP_FILE_EXTENSION);
	game = cb_get();
	map_data = read_map_file(open(argv[1], O_RDONLY));
	parse_map_file(game, map_data);
	cb_arrfree((void **) map_data);
	render(game);
	cb_exit(NULL, EXIT_SUCCESS);
}
