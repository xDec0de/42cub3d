/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:07:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 01:55:54 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(int x, int y, int size, int color)
{
	t_game	*game;
	int		i;

	game = fake_cb_get();
	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(&game->data, x + i, y, color);
		my_mlx_pixel_put(&game->data, x, y + i, color);
		my_mlx_pixel_put(&game->data, x + size, y + i, color);
		my_mlx_pixel_put(&game->data, x + i, y + size, color);
		i++;
	}
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&game->data, x, y, 0);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_game *game)
{
	move_player(&game->player, 5);
	clear_image(game);
	draw_square(game->player.x, game->player.y, 5, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (0);
}

void	render(void)
{
	t_game	*game;

	game = fake_cb_get();
	game->mlx = mlx_init();
	if (!game->mlx)
		fake_cb_exit(NULL, ERRC_MLX_INIT_FAIL);
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	if (!game->window)
		fake_cb_exit(NULL, ERRC_WINDOW_INIT_FAIL);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
		fake_cb_exit(NULL, ERRC_IMG_CREATION_FAIL);
	game->data.addr = mlx_get_data_addr(game->img, &game->data.bits_per_pixel,
			&game->data.line_length, &game->data.endian);
	mlx_hook(game->window, 17, 0L, close_window, game);
	mlx_key_hook(game->window, handle_key, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, &game->player);
	mlx_hook(game->window, 3, 1L << 1, key_release, &game->player);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
}
