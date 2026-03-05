/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:36:46 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/05 21:20:55 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"

static void	init_step(t_game *game, t_ray_step *step, float angle)
{
	step->cos_a = cosf(angle);
	step->sin_a = sinf(angle);
	step->x = game->player.x;
	step->y = game->player.y;
	step->prev_x = step->x;
	step->prev_y = step->y;
}

static void	continue_until_wall(t_game *game, t_ray_step *step)
{
	int	map_x;
	int	map_y;

	while (1)
	{
		map_x = (int)(step->x / TILE_SIZE);
		map_y = (int)(step->y / TILE_SIZE);
		if (game->map.grid[map_y][map_x] == '1')
			return ;
		if (DEBUG)
			my_mlx_pixel_put(&game->data, (int)step->x,
				(int)step->y, 0xFF0000);
		step->prev_x = step->x;
		step->prev_y = step->y;
		step->x += step->cos_a;
		step->y += step->sin_a;
	}
}

static void	compute_cells(t_ray_cells *cells, t_ray_step *step)
{
	cells->prev_x = (int)(step->prev_x / TILE_SIZE);
	cells->prev_y = (int)(step->prev_y / TILE_SIZE);
	cells->hit_x = (int)(step->x / TILE_SIZE);
	cells->hit_y = (int)(step->y / TILE_SIZE);
}

static void	set_hit_face(t_game *g, t_ray_step *s, t_ray_cells *c, t_ray *r)
{
	char	wx;
	char	wy;

	r->is_vertical = true;
	if (c->prev_x == c->hit_x && c->prev_y != c->hit_y)
		r->is_vertical = false;
	else if (c->prev_x != c->hit_x && c->prev_y != c->hit_y)
	{
		wx = g->map.grid[c->prev_y][c->hit_x];
		wy = g->map.grid[c->hit_y][c->prev_x];
		r->is_vertical = (fabsf(s->cos_a) > fabsf(s->sin_a));
		if (wx == '1' && wy != '1')
			r->is_vertical = true;
		else if (wx != '1' && wy == '1')
			r->is_vertical = false;
	}
	r->face = WEST;
	if (!r->is_vertical)
		r->face = NORTH;
	if (r->is_vertical && s->cos_a > 0.0f)
		r->face = EAST;
	if (!r->is_vertical && s->sin_a > 0.0f)
		r->face = SOUTH;
}

void	raycast_build_ray(t_game *game, t_ray *ray, float angle, int screen_x)
{
	t_ray_step	step;
	t_ray_cells	cells;
	float		dx;
	float		dy;
	float		a;

	init_step(game, &step, angle);
	continue_until_wall(game, &step);
	compute_cells(&cells, &step);
	set_hit_face(game, &step, &cells, ray);
	ray->angle = angle;
	ray->hit_x = step.x;
	ray->hit_y = step.y;
	ray->screen_x = screen_x;
	dx = step.x - game->player.x;
	dy = step.y - game->player.y;
	a = atan2f(dy, dx) - game->player.angle;
	ray->dist = sqrtf(dx * dx + dy * dy) * cosf(a);
}
