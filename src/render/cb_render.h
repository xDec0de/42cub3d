/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:10:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/03/05 19:48:59 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_RENDER_H
# define CB_RENDER_H

# include <stdbool.h>
# include <stddef.h>
# include "./cb_types.h"
# include "./cb_msg.h"
# include "cb_events.h"
# include <mlx.h>
# include <math.h>

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WINDOW_TITLE "cub3d"

# define PLAYER_SPEED 3
# define ANGLE_SPEED 0.03

# define TILE_SIZE 64
# define PI 3.14159265359

# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4

void	render(t_game *game);
int		draw_loop(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(int x, int y, int size, int color);
void	draw_map(t_map *map);
void	clear_image(t_game *game);
void	draw_ceiling_and_floor(t_game *game, int x, int ws, int we);
void	raycaster(t_game *game);
void	draw_wall_slice(t_game *game, float dist, int screen_x, t_ray ray);
void	my_mlx_pixel_put_color(t_data *data, int x, int y, t_color c);
void	raycast_build_ray(t_game *game, t_ray *ray, float angle, int screen_x);

#endif