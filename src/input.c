/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:47 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 04:00:38 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_finish_game(t_ctx *ctx)
{
	ft_printf(CYAN "Movements: " YELLOW "%d\n" RESET, ++ctx->movements);
	ft_printf(GREEN "Congratulations! You won!\n" RESET);
	success_exit(ctx);
}

static void	ft_move_dir(t_ctx *ctx, int dx, int dy)
{
	int		x;
	int		y;
	char	current_tile;

	x = ctx->map.player.x;
	y = ctx->map.player.y;
	current_tile = ctx->map.map_matris[y + dy][x + dx];
	if (current_tile != WALL)
	{
		if (current_tile == MAP_EXIT)
		{
			if (ctx->map.coins == 0)
				ft_finish_game(ctx);
			return ;
		}
		if (current_tile == COINS)
			ctx->map.coins--;
		ctx->map.map_matris[y][x] = FLOOR;
		ctx->map.player.x += dx;
		ctx->map.player.y += dy;
		ctx->map.map_matris[ctx->map.player.y][ctx->map.player.x] = PLAYER;
		ft_printf(CYAN "Movements: " YELLOW "%d\n" RESET,
			++ctx->movements);
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
