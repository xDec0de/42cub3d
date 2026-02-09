/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:09:20 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/08 21:55:27 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cb_parser.h"

static bool	parse_uchar(const char **data, unsigned char *out)
{
	int	res;
	int	digits;

	res = 0;
	digits = 0;
	while (cb_isdigit(**data))
	{
		res = res * 10 + (**data - '0');
		if (res > 255)
			return (false);
		(*data)++;
		digits++;
	}
	if (digits == 0)
		return (false);
	*out = (unsigned char) res;
	return (true);
}

static bool	parse_color(t_color *col, const char *line)
{
	const char		*data;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	data = line;
	if (!parse_uchar(&data, &r) || *data++ != ',')
		return (false);
	if (!parse_uchar(&data, &g) || *data++ != ',')
		return (false);
	if (!parse_uchar(&data, &b) || *data != '\0')
		return (false);
	col->r = r;
	col->g = g;
	col->b = b;
	return (true);
}

void	parse_colors(t_game *game, char **map_data)
{
	size_t	line_i;
	char	*line;
	bool	parse_res;

	line_i = 0;
	parse_res = true;
	while (true)
	{
		line = map_data[line_i];
		if (line == NULL || is_map_line(line))
			break ;
		if (cb_strstartswith(line, "F "))
			parse_res = parse_color(&game->map.floor_col, line + 2);
		else if (cb_strstartswith(line, "C "))
			parse_res = parse_color(&game->map.ceil_col, line + 2);
		if (!parse_res)
		{
			printf(ERR_INVALID_COLOR, line);
			cb_arrfree((void **) map_data);
			cb_exit(NULL, ERRC_INVALID_COLOR);
		}
		line_i++;
	}
}
