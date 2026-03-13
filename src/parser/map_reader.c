/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:38:41 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/13 20:37:38 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parser.h"

static void	free_helper(char *buf, char *all, int fd)
{
	free(buf);
	free(all);
	close(fd);
}

static void	read_fail(char *buf, char *all, int fd)
{
	free_helper(buf, all, fd);
	cb_exitf(printf(ERR_READ_FAIL, strerror(errno)), ERRC_READ_FAIL);
}

char	**read_map_file(int fd)
{
	char	*buf;
	char	*all;
	ssize_t	read_res;
	char	**file;

	if (fd < 0)
		cb_exitf(printf(ERR_OPEN_MAP, strerror(errno)), ERRC_OPEN_MAP);
	buf = cb_malloc(BUFSIZ + 1);
	all = cb_strdup("");
	read_res = read(fd, buf, BUFSIZ);
	while (read_res > 0)
	{
		buf[read_res] = '\0';
		all = cb_strjoin(all, buf);
		read_res = read(fd, buf, BUFSIZ);
	}
	if (read_res < 0)
		read_fail(buf, all, fd);
	file = cb_split(all, '\n');
	free_helper(buf, all, fd);
	return (file);
}
