/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:21:38 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/21 17:25:50 by rexposit         ###   ########.fr       */
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

int	close_window(void);
int	handle_key(int key, t_game *game);

#endif