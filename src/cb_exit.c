/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:34:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/09/12 04:51:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "cb_strutils.h"

void	cb_exit(char *msg, int ec)
{
	if (msg != NULL)
		write(STDOUT_FILENO, msg, cb_strlen(msg));
	exit(ec);
}
