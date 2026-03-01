/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:12:23 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/01 17:15:00 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_PARSER_H
# define CB_PARSER_H

# include "cb_msg.h"
# include "cb_strutils.h"
# include "cb_chutils.h"
# include "cb_mem.h"

void	parse_map_file(t_game *game, char **map_data);

void	validate_structure(char **grid, char **map_data);

void	parse_colors(t_game *game, char **map_data);

void	parse_assets(t_game *game, char **map_data);

bool	is_map_line(const char *line);

bool	find_player_pos(t_game *game);

char	**read_map_file(int fd);

#endif