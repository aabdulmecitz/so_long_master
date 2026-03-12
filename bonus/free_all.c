/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:51 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 19:13:42 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_all_mem(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_destroy_imgs(ctx);
	if (ctx->map_alloc && ctx->map.map_matris)
		free_map(ctx);
	free_double(ctx->wall, ctx->floor, ctx->coins, ctx->player_front);
	free_double(ctx->player_left, ctx->player_right, ctx->player_back, \
		ctx->exit_closed);
	free_double(ctx->open_exit, ctx->enemy_x_l, ctx->enemy_x_r, ctx->enemy_k);
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
		ctx->mlx_ptr = NULL;
	}
	free(ctx);
}

void	ft_destroy_imgs(t_ctx *ctx)
{
	int		i;
	t_img	*imgs[12];

	if (!ctx || !ctx->mlx_ptr)
		return ;
	imgs[0] = ctx->wall;
	imgs[1] = ctx->floor;
	imgs[2] = ctx->coins;
	imgs[3] = ctx->player_front;
	imgs[4] = ctx->player_left;
	imgs[5] = ctx->player_right;
	imgs[6] = ctx->player_back;
	imgs[7] = ctx->exit_closed;
	imgs[8] = ctx->open_exit;
	imgs[9] = ctx->enemy_k;
	imgs[10] = ctx->enemy_x_l;
	imgs[11] = ctx->enemy_x_r;

	i = 0;
	while (i < 12)
	{
		if (imgs[i] && imgs[i]->xpm_ptr)
		{
			mlx_destroy_image(ctx->mlx_ptr, imgs[i]->xpm_ptr);
			imgs[i]->xpm_ptr = NULL;
		}
		i++;
	}
	destroy_sprites(ctx);
}

void	free_map(t_ctx *ctx)
{
	int	i;

	if (!ctx->map.map_matris)
		return ;
	i = 0;
	while (i < ctx->map.rows)
		free(ctx->map.map_matris[i++]);
	free(ctx->map.map_matris);
}
