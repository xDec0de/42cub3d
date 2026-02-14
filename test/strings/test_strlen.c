/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:05:48 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/14 22:41:37 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

TEST(CATEGORY, "cb_strlen(\"Hi\" == 2)") {
	ASSERT_INT_EQUALS(cb_strlen("Hi"), 2);
}

TEST(CATEGORY, "cb_strlen(\"\" == 0)") {
	ASSERT_INT_EQUALS(cb_strlen(""), 0);
}
