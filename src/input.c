/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:47 by aozkaya           #+#    #+#             */
/*   Updated: 2026/03/12 18:32:49 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_dir(t_ctx *ctx, int dx, int dy)
{
	int	x;
	int	y;

	x = ctx->map.player.x;
	y = ctx->map.player.y;
	if (ctx->map.map_matris[y + dy][x + dx] != WALL)
	{
		if (ctx->map.map_matris[y + dy][x + dx] == MAP_EXIT)
		{
			if (ctx->map.coins == 0)
			{
				ft_printf("Movements: %d\n", ++ctx->movements);
				ft_printf("Congratulations! You won!\n");
				success_exit(ctx);
			}
			return ;
		}
		if (ctx->map.map_matris[y + dy][x + dx] == COINS)
			ctx->map.coins--;
		ctx->map.map_matris[y][x] = FLOOR;
		ctx->map.player.x += dx;
		ctx->map.player.y += dy;
		ctx->map.map_matris[ctx->map.player.y][ctx->map.player.x] = PLAYER;
		ft_printf("Movements: %d\n", ++ctx->movements);
		render_map(ctx);
	}
}

int	key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESC)
		success_exit(ctx);
	else if (keycode == KEY_W || keycode == KEY_UP)
		ft_move_dir(ctx, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_dir(ctx, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move_dir(ctx, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_dir(ctx, 1, 0);
	return (0);
}
