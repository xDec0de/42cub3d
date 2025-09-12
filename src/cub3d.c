/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 04:56:41 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "cb_msg.h"
#include "cb_types.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(ERR_ARGC, argv[0]);
		return (ERRC_ARGC);
	}
	return (EXIT_SUCCESS);
}
