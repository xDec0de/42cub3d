/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:10:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/07 13:10:09 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_RENDER_H
# define CB_RENDER_H

# include <stdbool.h>
# include <stddef.h>
# include "./cb_types.h"
# include "./cb_msg.h"

void	render(void);
t_game	*fake_cb_get(void);

#endif