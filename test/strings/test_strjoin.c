/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:39:55 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/15 20:33:58 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

TEST(CATEGORY, "cb_strjoin(\"Hello\", \" world\") == \"Hello world\"") {
	ASSERT_STR_EQUALS_FREE(cb_strjoin(cb_strdup("Hello"), " world"), "Hello world");
}

TEST(CATEGORY, "cb_strjoin(\"Hello\", NULL) == NULL") {
	ASSERT_NULL(cb_strjoin("Hello", NULL));
}

TEST(CATEGORY, "cb_strjoin(NULL, \"Hello\") == NULL") {
	ASSERT_NULL(cb_strjoin(NULL, "Hello"));
}
