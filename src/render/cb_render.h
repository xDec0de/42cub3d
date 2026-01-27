/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:10:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/27 01:56:08 by rexposit         ###   ########.fr       */
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

void	render(void);
t_game	*fake_cb_get(void);
void	fake_cb_exit(char *msg, int ec);
int		draw_loop(t_game *game);

#endif