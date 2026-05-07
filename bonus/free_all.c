/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:51 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 04:38:07 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_all_mem(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_destroy_imgs(ctx);
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
		ctx->mlx_ptr = NULL;
	}
	gc_free_all(&ctx->gc);
	free(ctx);
}

static void	def_imgs_to_arr(t_ctx *ctx, t_img **arr)
{
	arr[0] = ctx->wall;
	arr[1] = ctx->floor;
	arr[2] = ctx->coins;
	arr[3] = ctx->player_front;
	arr[4] = ctx->player_left;
	arr[5] = ctx->player_right;
	arr[6] = ctx->player_back;
	arr[7] = ctx->exit_closed;
	arr[8] = ctx->open_exit;
	arr[9] = ctx->enemy_k;
	arr[10] = ctx->enemy_x_l;
	arr[11] = ctx->enemy_x_r;
}

void	ft_destroy_imgs(t_ctx *ctx)
{
	int		i;
	t_img	*imgs[12];

	if (!ctx || !ctx->mlx_ptr)
		return ;
	def_imgs_to_arr(ctx, imgs);
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
