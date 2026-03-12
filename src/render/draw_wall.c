/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/13 00:00:00 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static t_texture	*get_tex_for_face(t_assets *assets, int face)
{
	if (face == SOUTH)
		return (&assets->south);
	if (face == WEST)
		return (&assets->west);
	if (face == EAST)
		return (&assets->east);
	return (&assets->north);
}

static int	get_wall_tex_x(t_ray ray, t_texture *tex)
{
	float	hit_coord;
	float	offset;
	int		tex_x;

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
	return (tex_x);
}

static void	init_wall_data(float dist, t_texture *tex, t_ray ray,
		t_wall_data *wd)
{
	wd->height = (TILE_SIZE / dist) * (WINDOW_WIDTH / 2);
	wd->draw_start = (WINDOW_HEIGHT - wd->height) / 2;
	wd->wall_start = wd->draw_start;
	wd->wall_end = wd->wall_start + wd->height;
	if (wd->wall_start < 0)
		wd->wall_start = 0;
	if (wd->wall_end > WINDOW_HEIGHT)
		wd->wall_end = WINDOW_HEIGHT;
	wd->tex_x = get_wall_tex_x(ray, tex);
	wd->step = (float)tex->height / wd->height;
	wd->tex_pos = (wd->wall_start - wd->draw_start) * wd->step;
	wd->bpp_bytes = tex->data.bits_per_pixel / 8;
}

static void	draw_tex_column(t_game *game, t_texture *tex,
		t_wall_data *wd, int screen_x)
{
	int		y;
	int		tex_y;
	char	*src;
	int		color;

	y = wd->wall_start;
	while (y < wd->wall_end)
	{
		tex_y = (int)wd->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		src = tex->data.addr
			+ (tex_y * tex->data.line_length)
			+ (wd->tex_x * wd->bpp_bytes);
		color = *(unsigned int *)src;
		my_mlx_pixel_put(&game->data, screen_x, y, color);
		wd->tex_pos += wd->step;
		y++;
	}
}

void	draw_wall_slice(t_game *game, float dist, int screen_x, t_ray ray)
{
	t_texture	*tex;
	t_wall_data	wd;

	tex = get_tex_for_face(&game->assets, ray.face);
	init_wall_data(dist, tex, ray, &wd);
	draw_ceiling_and_floor(game, screen_x, wd.wall_start, wd.wall_end);
	draw_tex_column(game, tex, &wd, screen_x);
}
