/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:20 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 19:13:50 by aozkaya          ###   ########.fr       */
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

void destroy_sprites(t_ctx *ctx)
{
	free(ctx->wall);
	free(ctx->floor);
	free(ctx->coins);
	free(ctx->player_front);
	free(ctx->player_left);
	free(ctx->player_right);
	free(ctx->player_back);
	free(ctx->open_exit);
	free(ctx->exit_closed);
	free(ctx->enemy_x_l);
	free(ctx->enemy_x_r);
	free(ctx->enemy_k);
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
