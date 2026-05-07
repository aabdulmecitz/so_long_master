/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:33:20 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 04:00:22 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_border(t_ctx *ctx, int x, int y)
{
	if (y == 0 || y == ctx->map.rows - 1)
		return (1);
	if (x == 0 || x == ctx->map.columns - 1)
		return (1);
	return (0);
}

static void	ft_count_elements(t_ctx *ctx, int x, int y)
{
	char	tile;

	tile = ctx->map.map_matris[y][x];
	if (ft_is_border(ctx, x, y) && tile != WALL)
		error("Map is not surrounded by walls.", ctx);
	if (tile == PLAYER)
	{
		ctx->map.players++;
		ctx->map.player.y = y;
		ctx->map.player.x = x;
	}
	else if (tile == MAP_EXIT)
		ctx->map.exit++;
	else if (tile == COINS)
		ctx->map.coins++;
	else if (tile != WALL && tile != FLOOR && tile != PLAYER
		&& tile != MAP_EXIT && tile != COINS)
		error("Invalid character in map.", ctx);
}

void	ft_check_elements(t_ctx *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map.rows)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			ft_count_elements(ctx, x, y);
			x++;
		}
		y++;
	}
	if (ctx->map.players != 1)
		error("Map must contain exactly one starting location ('P')", ctx);
	if (ctx->map.exit != 1)
		error("Map must contain exactly one exit ('E')", ctx);
	if (ctx->map.coins < 1)
		error("Map must contain at least one collectible ('C')", ctx);
}

void	ft_check_rectangular(t_ctx *ctx)
{
	int		i;
	size_t	first_row_len;

	if (ctx->map.rows == 0)
		error("Map is empty!", ctx);
	first_row_len = ft_strlen(ctx->map.map_matris[0]);
	ctx->map.columns = first_row_len;
	i = 1;
	while (i < ctx->map.rows)
	{
		if (ft_strlen(ctx->map.map_matris[i]) != first_row_len)
			error("Map is not rectangular!", ctx);
		i++;
	}
}

void	map_checker(t_ctx *ctx)
{
	ft_check_rectangular(ctx);
	ft_check_elements(ctx);
	general_checker(ctx);
}
