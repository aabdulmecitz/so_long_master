/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ctx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:42 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:47:13 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long_init(t_ctx *ctx);
void	ft_init_mlx(t_ctx *ctx);
void	ft_init_sprites(t_ctx *ctx);

void	so_long_init(t_ctx *ctx)
{
	ctx->ctx_num = 0;
	ctx->map.coins = 0;
	ctx->map.exit = 0;
	ctx->map.players = 0;
	ctx->movements = 0;
	ctx->enemy_k_num = 0;
	ctx->enemy_x_num = 0;
	conf_null(ctx);
	ctx->map.columns = ft_strlen(ctx->map.map_matris[0]) - 1;
	while (ctx->map.map_matris[ctx->map.rows])
		ctx->map.rows++;
	ctx->player_dir = FRONT;
	ft_init_mlx(ctx);
	ft_init_sprites(ctx);
	ft_printf(GREEN "ctx initialization successful!\n" RESET);
}

void	ft_init_mlx(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	if (!ctx->mlx_ptr)
		error("Couldn't find mlx pointer. Try it using a VNC.", ctx);
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr,
			(ctx->map.columns + 1) * IMG_WIDTH,
			(ctx->map.rows + 2) * IMG_HEIGHT, "so_long");
	if (!ctx->win_ptr)
	{
		free(ctx->mlx_ptr);
		error("Couldn't create the Window.", ctx);
	}
}

void	load_sprite(t_img *sprite, void *mlx, char *path, t_ctx *ctx)
{
	if (!sprite)
		error("Sprite pointer is NULL.", ctx);
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
	ft_printf(CYAN "Loading sprite from path: %s\n" RESET, path);
	if (!sprite->xpm_ptr)
	{
		ft_printf(RED "Failed to load sprite: %s\n" RESET, path);
		error("Couldn't find a sprite. Does it exist?", ctx);
	}
}

void	ft_init_sprites(t_ctx *ctx)
{
	ctx->wall = malloc(sizeof(t_img));
	ctx->floor = malloc(sizeof(t_img));
	ctx->coins = malloc(sizeof(t_img));
	ctx->player_front = malloc(sizeof(t_img));
	ctx->player_left = malloc(sizeof(t_img));
	ctx->player_right = malloc(sizeof(t_img));
	ctx->player_back = malloc(sizeof(t_img));
	ctx->open_exit = malloc(sizeof(t_img));
	ctx->exit_closed = malloc(sizeof(t_img));
	ctx->enemy_x_l = malloc(sizeof(t_img));
	ctx->enemy_x_r = malloc(sizeof(t_img));
	ctx->enemy_k = malloc(sizeof(t_img));
	if (!ctx->wall || !ctx->floor || !ctx->coins
		|| !ctx->player_front || !ctx->player_left
		|| !ctx->player_right || !ctx->player_back
		|| !ctx->open_exit || !ctx->exit_closed
		|| !ctx->enemy_x_l || !ctx->enemy_x_r || !ctx->enemy_k)
		error("Memory allocation failed for one of the sprites.", ctx);
	load_all_sprites(ctx);
}
