/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:07:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/11 15:36:31 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

int	draw_loop(t_game *game)
{
	move_player(&game->player, PLAYER_SPEED, ANGLE_SPEED, game->map.grid);
	clear_image(game);
	if (DEBUG)
	{
		draw_square(game->player.x, game->player.y, 10, 0x00FF00);
		draw_map(&game->map);
	}
	raycaster(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (0);
}

static void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx,
			path, &tex->width, &tex->height);
	if (tex->img == NULL)
		cb_exit(ERR_TEX_LOAD_FAIL, ERRC_TEX_LOAD_FAIL);
	tex->data.addr = mlx_get_data_addr(tex->img, &tex->data.bits_per_pixel,
			&tex->data.line_length, &tex->data.endian);
	if (tex->data.addr == NULL)
		cb_exit(ERR_TEX_DATA_ADDR_FAIL, ERRC_TEX_DATA_ADDR_FAIL);
}

static void	load_textures(t_game *game)
{
	load_texture(game, &game->assets.north, game->map.no_path);
	load_texture(game, &game->assets.south, game->map.so_path);
	load_texture(game, &game->assets.west, game->map.we_path);
	load_texture(game, &game->assets.east, game->map.ea_path);
}

void	render(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		cb_exit(ERR_MLX_INIT_FAIL, ERRC_MLX_INIT_FAIL);
	load_textures(game);
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game->window)
		cb_exit(ERR_WINDOW_INIT_FAIL, ERRC_WINDOW_INIT_FAIL);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
		cb_exit(ERR_IMG_CREATION_FAIL, ERRC_IMG_CREATION_FAIL);
	game->data.addr = mlx_get_data_addr(game->img, &game->data.bits_per_pixel,
			&game->data.line_length, &game->data.endian);
	mlx_hook(game->window, 17, 0L, close_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, &game->player);
	mlx_hook(game->window, 3, 1L << 1, key_release, &game->player);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
}
