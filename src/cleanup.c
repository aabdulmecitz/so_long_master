/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:33 by aozkaya           #+#    #+#             */
/*   Updated: 2026/03/12 19:01:31 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(void *p1, void *p2, void *p3, void *p4)
{
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}

void	free_map_inside(t_map *map)
{
	int	i;

	if (!map->map_matris)
		return ;
	i = 0;
	while (i < map->rows)
		free(map->map_matris[i++]);
	free(map->map_matris);
}

static void	ft_destroy_imgs(t_ctx *ctx)
{
	if (!ctx->mlx_ptr)
		return ;
	if (ctx->wall && ctx->wall->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->wall->xpm_ptr);
	if (ctx->floor && ctx->floor->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->floor->xpm_ptr);
	if (ctx->coins && ctx->coins->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->coins->xpm_ptr);
	if (ctx->player && ctx->player->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->player->xpm_ptr);
	if (ctx->exit && ctx->exit->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->exit->xpm_ptr);
	if (ctx->exit_open && ctx->exit_open->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->exit_open->xpm_ptr);
}

void	success_exit(t_ctx *ctx)
{
	ft_printf(GREEN "\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     " YELLOW "🎉  CONGRATULATIONS!  🎉" GREEN "             *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     You've escaped with all the loot!      *\n");
	ft_printf("  *     Final Movements: " YELLOW "%d" GREEN "                   *\n", ctx->movements);
	ft_printf("  *                                            *\n");
	ft_printf("  *     " CYAN "Thank you for playing so_long! 🐬" GREEN "       *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n" RESET);
	ft_printf("\n");
	ft_destroy_imgs(ctx);
	if (ctx->map_alloc)
		free_map_inside(&ctx->map);
	free_double(ctx->wall, ctx->floor, ctx->coins, ctx->player);
	free(ctx->exit);
	free(ctx->exit_open);
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
	}
	free(ctx);
	exit(0);
}

void	error(char *msg, t_ctx *ctx)
{
	ft_printf(RED "\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("  #          " YELLOW "⚠️   ERROR OCCURRED  ⚠️" RED "           #\n");
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("    Reason: %s\n", msg);
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n" RESET);
	ft_printf("\n");
	if (ctx)
	{
		ft_destroy_imgs(ctx);
		if (ctx->map_alloc)
			free_map_inside(&ctx->map);
		free_double(ctx->wall, ctx->floor, ctx->coins, ctx->player);
		free(ctx->exit);
		free(ctx->exit_open);
		if (ctx->mlx_ptr)
		{
			if (ctx->win_ptr)
				mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
			mlx_destroy_display(ctx->mlx_ptr);
			free(ctx->mlx_ptr);
		}
		free(ctx);
	}
	exit(1);
}

int	win_destroy(t_ctx *ctx)
{
	success_exit(ctx);
	return (0);
}
