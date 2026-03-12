/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:49:44 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/09 12:09:55 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static void
	draw_ceiling_and_floor(t_game *game, int x, int wall_start, int wall_end)
{
	int	y;

	if (wall_start < 0)
		wall_start = 0;
	if (wall_end > WINDOW_HEIGHT)
		wall_end = WINDOW_HEIGHT;
	y = 0;
	while (y < wall_start)
	{
		my_mlx_pixel_put_color(&game->data, x, y, game->map.ceil_col);
		y++;
	}
	y = wall_end;
	while (y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put_color(&game->data, x, y, game->map.floor_col);
		y++;
	}
}

void	draw_square(int x, int y, int size, int color)
{
	t_game	*game;
	int		i;

	game = cb_get();
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

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y] != NULL)
	{
		x = 0;
		while (map->grid[y][x] != '\0')
		{
			if (map->grid[y][x] == '1')
				draw_square(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0x0000FF);
			x++;
		}
		y++;
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

void	draw_wall_slice(t_game *game, float dist, int screen_x, t_ray ray)
{
	float		height;
	int			wall_start;
	int			wall_end;
	int			draw_start;
	t_texture	*tex;
	float		hit_coord;
	float		offset;
	int			tex_x;
	float		step;
	float		tex_pos;
	int			y;
	int			tex_y;
	char		*src;
	int			color;
	int			bpp_bytes;

	height = (TILE_SIZE / dist) * (WINDOW_WIDTH / 2);
	draw_start = (WINDOW_HEIGHT - height) / 2;
	wall_start = draw_start;
	wall_end = wall_start + height;

	if (wall_start < 0)
		wall_start = 0;
	if (wall_end > WINDOW_HEIGHT)
		wall_end = WINDOW_HEIGHT;

	draw_ceiling_and_floor(game, screen_x, wall_start, wall_end);
	tex = &game->assets.north;
	if (ray.face == SOUTH)
		tex = &game->assets.south;
	else if (ray.face == WEST)
		tex = &game->assets.west;
	else if (ray.face == EAST)
		tex = &game->assets.east;
	hit_coord = ray.hit_x;
	if (ray.is_vertical)
		hit_coord = ray.hit_y;
	offset = fmodf(hit_coord, TILE_SIZE);
	if (offset < 0)
		offset += TILE_SIZE;
	tex_x = (int)(offset * tex->width / TILE_SIZE);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	step = (float)tex->height / height;
	tex_pos = (wall_start - draw_start) * step;
	bpp_bytes = tex->data.bits_per_pixel / 8;
	y = wall_start;
	while (y < wall_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;

		src = tex->data.addr
			+ (tex_y * tex->data.line_length)
			+ (tex_x * bpp_bytes);
		color = *(unsigned int *)src;

		my_mlx_pixel_put(&game->data, screen_x, y, color);

		tex_pos += step;
		y++;
	}
}
