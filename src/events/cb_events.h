/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:21:38 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/29 22:05:16 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_EVENTS_H
# define CB_EVENTS_H

# include <stdbool.h>
# include <stddef.h>
# include "./cb_types.h"
# include "./cb_msg.h"
# include "cb_render.h"
# include <mlx.h>
# include <X11/keysym.h>

# define KEY_ESC XK_Escape
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_RIGHT XK_l
# define KEY_LEFT XK_j

int		close_window(void);
int		handle_key(int key, t_game *game);
int		key_press(int key, t_player *player);
int		key_release(int key, t_player *player);
void	move_player(t_player *player,
			int speed, float angle_speed, char **grid);
void	get_angle_vectors(t_player *player, float *cos_a, float *sin_a);

#endif