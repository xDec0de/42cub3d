/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:07:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/26 11:44:19 by rexposit         ###   ########.fr       */
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
	draw_square(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10, 0x00FF00);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	mlx_hook(game->window, 17, 0L, close_window, game);
	mlx_key_hook(game->window, handle_key, game);
	mlx_loop(game->mlx);
}
