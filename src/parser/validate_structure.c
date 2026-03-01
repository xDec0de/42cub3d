/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:13:27 by daniema3          #+#    #+#             */
/*   Updated: 2026/03/01 17:16:40 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parser.h"

static bool	is_enclosed(char **grid, int row, int col)
{
	if (!grid[row - 1] || !grid[row + 1])
		return (false);
	if (grid[row][col - 1] == ' ' || grid[row][col - 1] == '\0')
		return (false);
	if (grid[row][col + 1] == ' ' || grid[row][col + 1] == '\0')
		return (false);
	if (grid[row - 1][col] == ' ' || grid[row - 1][col] == '\0')
		return (false);
	if (grid[row + 1][col] == ' ' || grid[row + 1][col] == '\0')
		return (false);
	return (true);
}

static bool	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	validate_structure(char **grid, char **map_data)
{
	int	row;
	int	col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (is_walkable(grid[row][col]))
			{
				if (row == 0 || !grid[row + 1] || !is_enclosed(grid, row, col))
				{
					cb_arrfree((void **) map_data);
					cb_exit(ERR_INVALID_MAP, ERRC_INVALID_MAP);
				}
			}
			col++;
		}
		row++;
	}
}
