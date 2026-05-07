/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:20 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 04:54:02 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_double(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	if (ptr1)
		free(ptr1);
	if (ptr1)
		free(ptr2);
	if (ptr1)
		free(ptr3);
	if (ptr1)
		free(ptr4);
}

void	free_img_list(t_img *head, void *mlx_ptr)
{
	t_img	*current;
	t_img	*temp;

	current = head;
	while (current)
	{
		temp = current->next;
		if (current->xpm_ptr && mlx_ptr)
			mlx_destroy_image(mlx_ptr, current->xpm_ptr);
		free(current);
		current = temp;
	}
}

void	destroy_sprites(t_ctx *ctx)
{
	ctx->wall = NULL;
	ctx->floor = NULL;
	ctx->coins = NULL;
	ctx->player_front = NULL;
	ctx->player_left = NULL;
	ctx->player_right = NULL;
	ctx->player_back = NULL;
	ctx->open_exit = NULL;
	ctx->exit_closed = NULL;
	ctx->enemy_x_l = NULL;
	ctx->enemy_x_r = NULL;
	ctx->enemy_k = NULL;
}

void	free_map_inside(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map_matris[i]);
		i++;
	}
	free(map->map_matris);
	free(map);
}

int	win_destroy(t_ctx *ctx)
{
	if (!ctx)
	{
		free_all_mem(ctx);
	}
	exit(0);
	return (0);
}
