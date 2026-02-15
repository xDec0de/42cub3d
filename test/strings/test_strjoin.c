/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:39:55 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/15 17:31:25 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

TEST(CATEGORY, "cb_strjoin(\"Hello\", \" world\" == \"Hello world\")") {
	char	*hello = cb_strdup("Hello");
	char	*str = cb_strjoin(hello, " world");
	ASSERT_STR_EQUALS_FREE(str, "Hello world");
}
