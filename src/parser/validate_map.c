/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:57:53 by rexposit          #+#    #+#             */
/*   Updated: 2025/09/10 21:02:28 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_border(t_game *game, int x, int y)
{
	if ((y == 0 || y == game->map.height - 1 || x == 0
			|| x == game->map.width - 1) && game->map.grid[y][x] != '1')
	{
		ft_printf("Error: El mapa debe estar cerrado con paredes\n");
		free_resources(game);
		exit(1);
	}
}

void	check_map_validity(t_game *game)
{
	if (game->map.grid == NULL || game->map.height == 0 || game->map.width == 0)
	{
		ft_printf("Error: El mapa no puede estar vacío\n");
		clean_exit(game);
	}
	if (game->map.height > 100)
	{
		ft_printf("Error: El mapa es demasiado alto\n");
		clean_exit(game);
	}
	if (game->map.width > 100)
	{
		ft_printf("Error: El mapa es demasiado largo\n");
		clean_exit(game);
	}
}

void	copy_map_and_fill(t_game *game, char ***map_copy)
{
	int	y;

	*map_copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!(*map_copy))
		return ;
	y = 0;
	while (y < game->map.height)
	{
		(*map_copy)[y] = ft_strdup(game->map.grid[y]);
		if (!(*map_copy)[y])
		{
			while (y--)
				free((*map_copy)[y]);
			free(*map_copy);
			*map_copy = NULL;
			return ;
		}
		y++;
	}
	(*map_copy)[y] = NULL;
}

void	validate_map(t_game *game)
{
	int	p_cnt;
	int	e_cnt;

	p_cnt = 0;
	e_cnt = 0;
	check_map_validity(game);
	validate_map_characters(game, &p_cnt, &e_cnt);
	validate_map_elements(game, p_cnt, e_cnt);
	if (!is_map_accessible(game))
	{
		ft_printf("Error: La salida o los coleccionables no son accesibles\n");
		clean_exit(game);
	}
}
