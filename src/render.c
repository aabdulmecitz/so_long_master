/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:33:09 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 03:59:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_inside(t_map *map)
{
	int	i;

	if (!map || !map->map_matris)
		return ;
	i = 0;
	while (i < map->rows)
		free(map->map_matris[i++]);
	free(map->map_matris);
}

static void	put_tile(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == WALL)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			ctx->wall->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == FLOOR)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			ctx->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == COINS)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			ctx->coins->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == PLAYER)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			ctx->player->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == MAP_EXIT)
	{
		if (ctx->map.coins == 0)
			mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
				ctx->exit_open->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
		else
			mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
				ctx->exit->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	}
}

void	render_map(t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map.rows)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			put_tile(ctx, x, y);
			x++;
		}
		y++;
	}
}
