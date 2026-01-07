/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:10:05 by rexposit          #+#    #+#             */
/*   Updated: 2026/01/07 09:38:06 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdbool.h>
# include <stddef.h>
# include "./cb_types.h"
# include "./cb_msg.h"

void	render(void);
t_game	*fake_cb_get(void);

#endif