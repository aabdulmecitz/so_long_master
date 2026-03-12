/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:30 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/31 18:52:47 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemies_value(t_enemy *new_enemy, t_ctx *ctx, int x, int y);

void	init_enemies(t_ctx *ctx)
{
	int		x;
	int		y;
	t_enemy	*new_enemy;

	ctx->enemy = NULL;
	y = 0;
	while (y < ctx->map.rows)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			if (ctx->enemy_x_num == 0)
				return ;
			if (ctx->map.map_matris[y][x] == WANDER_ENEMY)
			{
				new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
				if (!new_enemy)
					return ;
				init_enemies_value(new_enemy, ctx, x, y);
			}
			x++;
		}
		y++;
	}
}

void	init_enemies_value(t_enemy *new_enemy, t_ctx *ctx, int x, int y)
{
	new_enemy->x = x;
	new_enemy->y = y;
	new_enemy->dir = rand() % 4;
	new_enemy->last_move_time = time(NULL);
	new_enemy->next = ctx->enemy;
	ctx->enemy = new_enemy;
	ctx->enemy_x_num--;
}
