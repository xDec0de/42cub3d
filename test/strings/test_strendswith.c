/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strendswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:34:43 by daniema3          #+#    #+#             */
/*   Updated: 2026/02/15 20:38:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

TEST(CATEGORY, "cb_strendswith(\"map.cub\", \".cub\") == true") {
	ASSERT_TRUE(cb_strendswith("map.cub", ".cub"));
}

TEST(CATEGORY, "cb_strendswith(\".cub\", \".cub\") == true") {
	ASSERT_TRUE(cb_strendswith(".cub", ".cub"));
}

TEST(CATEGORY, "cb_strendswith(\"cub\", \".cub\") == false") {
	ASSERT_FALSE(cb_strendswith("cub", ".cub"));
}

TEST(CATEGORY, "cb_strendswith(\".cub\", \"\") == true") {
	ASSERT_TRUE(cb_strendswith(".cub", ""));
}
