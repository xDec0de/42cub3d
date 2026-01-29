/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:10:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/29 17:35:56 by rexposit         ###   ########.fr       */
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
# define TILE_SIZE 64
# define PI 3.14159265359
# define DEBUG 0

t_game	*fake_cb_get(void);
void	fake_cb_exit(char *msg, int ec);
void	render(void);
int		draw_loop(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(int x, int y, int size, int color);
void	draw_map(t_map *map);
void	clear_image(t_game *game);
void	raycaster(t_game *game);
void	draw_wall_slice( t_game *game, float dist, int screen_x);
void	my_mlx_pixel_put_color(t_data *data, int x, int y, t_color c);

#endif