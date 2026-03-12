/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:42:34 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:36:05 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_ctx *ctx, t_enemy *enemy, int new_x, int new_y);

int	is_valid_location(t_ctx *ctx, int x, int y)
{
	if (x < 0 || x >= ctx->map.columns || y < 0 || y >= ctx->map.rows)
		return (0);
	if (ctx->map.map_matris[y][x] == WALL
		|| ctx->map.map_matris[y][x] == STAT_ENEMY
		|| ctx->map.map_matris[y][x] == WANDER_ENEMY
		|| ctx->map.map_matris[y][x] == COINS
		|| ctx->map.map_matris[y][x] == MAP_EXIT)
		return (0);
	return (1);
}

void	enemy_movement(t_ctx *ctx, t_enemy *enemy)
{
	time_t	current_time;
	int		new_x;
	int		new_y;

	current_time = time(NULL);
	if (difftime(current_time, enemy->last_move_time) < 0.1)
		return ;
	new_x = enemy->x;
	new_y = enemy->y;
	if (enemy->dir == BACK)
		new_y--;
	else if (enemy->dir == FRONT)
		new_y++;
	else if (enemy->dir == RIGHT)
		new_x++;
	else if (enemy->dir == LEFT)
		new_x--;
	move_enemy(ctx, enemy, new_x, new_y);
	enemy->last_move_time = current_time;
}

void	move_enemy(t_ctx *ctx, t_enemy *enemy, int new_x, int new_y)
{
	if (is_valid_location(ctx, new_x, new_y))
	{
		if (ctx->map.map_matris[new_y][new_x] == PLAYER)
		{
			failed_msg();
			win_destroy(ctx);
		}
		ctx->map.map_matris[enemy->y][enemy->x] = FLOOR;
		enemy->x = new_x;
		enemy->y = new_y;
		ctx->map.map_matris[new_y][new_x] = WANDER_ENEMY;
	}
	else
	{
		enemy->dir = rand() % 4;
		if (enemy->dir == 0)
			enemy->dir = BACK;
		else if (enemy->dir == 1)
			enemy->dir = FRONT;
		else if (enemy->dir == 2)
			enemy->dir = LEFT;
		else
			enemy->dir = RIGHT;
	}
}

void	handle_enemies(t_ctx *ctx)
{
	t_enemy	*current;

	current = ctx->enemy;
	while (current)
	{
		enemy_movement(ctx, current);
		current = current->next;
	}
}
