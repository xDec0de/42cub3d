/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/13 17:31:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "cb_msg.h"
#include "cb_strutils.h"
#include "cb_mem.h"

char	**read_map_file(int fd)
{
	char	*buf;
	char	**file;
	int		read_res;

	buf = cb_malloc(BUFSIZ);
	if (fd < 0)
		cb_exitf(printf(ERR_OPEN_MAP, strerror(errno)), ERRC_OPEN_MAP);
	read_res = read(fd, buf, BUFSIZ);
	while (read_res != 0)
	{
		if (read_res < 0)
		{
			close(fd);
			cb_exitf(printf(ERR_READ_FAIL, strerror(errno)), ERRC_READ_FAIL);
		}
		read_res = read(fd, buf, BUFSIZ);
	}
	printf("%s\n", buf);
	file = cb_split(buf, '\n');
	free(buf);
	close(fd);
	return (file);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map;

	if (argc != 2)
		cb_exitf(printf(ERR_ARGC, argv[0]), ERRC_ARGC);
	if (!cb_strendswith(argv[1], ".cub"))
		cb_exit(ERR_MAP_FILE_EXTENSION, ERRC_MAP_FILE_EXTENSION);
	game = cb_get();
	map = read_map_file(open(argv[1], O_RDONLY));
	(void) game;
	cb_arrfree((void **) map);
	cb_exit(NULL, EXIT_SUCCESS);
}
