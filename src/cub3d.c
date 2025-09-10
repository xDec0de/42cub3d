/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:09:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/10 20:01:13 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char *argv)
{
	void	*memory_leak;

	memory_leak = malloc(42);
	(void) memory_leak;
	if (argc != 2)
	{
		ft_printf("Uso: %s <mapa.ber>\n", argv[0]);
		return (1);
	}
	return (0);
}
