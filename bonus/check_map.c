/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:08 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 19:11:35 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_rectanglular(t_ctx *ctx);
void	ft_check_elements(t_ctx *ctx);
void	ft_search_elements(t_ctx *ctx);
void	ft_count_elements(t_ctx *ctx, int x, int y);

void	map_checker(t_ctx *ctx)
{
	ft_check_rectanglular(ctx);
	ft_check_elements(ctx);
	general_checker(ctx);
}

void	ft_check_rectanglular(t_ctx *ctx)
{
	int	i;
	int	first_row_len;
	int	current_row_len;

	if (ctx->map.rows == 0)
		return ;
	first_row_len = (int)ft_strlen(ctx->map.map_matris[0]);
	i = 1;
	while (i < ctx->map.rows)
	{
		current_row_len = (int)ft_strlen(ctx->map.map_matris[i]);
		if (current_row_len != first_row_len)
		{
			ft_printf(RED "%s , current row len: %d , first row len: \
				%d\n" RESET, ctx->map.map_matris[i], current_row_len, \
				first_row_len);
			(ft_destroy_imgs(ctx), error("Map is not rectangular!", ctx));
			return ;
		}
		i++;
	}
	ctx->map.columns++;
	ft_printf(GREEN "Map is rectangular!\n" RESET);
}

void	ft_check_elements(t_ctx *ctx)
{
	ft_search_elements(ctx);
	if (ctx->map.players != 1)
	{
		ft_destroy_imgs(ctx);
		error("Map must contain exactly one starting location ('P')", \
			ctx);
	}
	if (ctx->map.exit != 1)
	{
		ft_destroy_imgs(ctx);
		error("Map must contain exactly one exit ('E')", ctx);
	}
	if (ctx->map.coins < 1)
	{
		ft_destroy_imgs(ctx);
		error("Map must contain at least one collectible ('C')", ctx);
	}
}

void	ft_search_elements(t_ctx *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map.rows)
	{
		ft_printf(CYAN "|%s| size: %d|\n" RESET, ctx->map.map_matris[y], \
				(int)ft_strlen(ctx->map.map_matris[y]));
		x = 0;
		while (x < ctx->map.columns)
		{
			ft_count_elements(ctx, x, y);
			x++;
		}
		y++;
	}
}

void	ft_count_elements(t_ctx *ctx, int x, int y)
{
	if ((y == 0 || y == ctx->map.rows - 1 || x == 0 || \
x == ctx->map.columns - 1) && ctx->map.map_matris[y][x] != WALL)
		(ft_destroy_imgs(ctx), error("Invalid Map.", ctx));
	if (ctx->map.map_matris[y][x] == PLAYER)
	{
		ctx->map.players++;
		ctx->map.player.y = y;
		ctx->map.player.x = x;
	}
	else if (ctx->map.map_matris[y][x] == MAP_EXIT)
		ctx->map.exit++;
	else if (ctx->map.map_matris[y][x] == COINS)
		ctx->map.coins++;
	else if (ctx->map.map_matris[y][x] == STAT_ENEMY)
		ctx->enemy_k_num++;
	else if (ctx->map.map_matris[y][x] == WANDER_ENEMY)
		ctx->enemy_x_num++;
	else if (ctx->map.map_matris[y][x] != WALL
					&& ctx->map.map_matris[y][x] != FLOOR &&
				ctx->map.map_matris[y][x] != PLAYER
					&& ctx->map.map_matris[y][x] != MAP_EXIT &&
				ctx->map.map_matris[y][x] != COINS
					&& ctx->map.map_matris[y][x] != WANDER_ENEMY &&
				ctx->map.map_matris[y][x] != STAT_ENEMY)
		(ft_destroy_imgs(ctx), error("Invalid character in map", ctx));
}
