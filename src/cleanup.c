/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:33 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 03:59:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_ctx(t_ctx *ctx)
{
	if (ctx && ctx->mlx_ptr)
	{
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
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
	}
	gc_free_all(&ctx->gc);
	free(ctx);
}

void	success_exit(t_ctx *ctx)
{
	ft_printf(GREEN "\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     " YELLOW "🎉  CONGRATULATIONS!  🎉"
		GREEN "             *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     You've escaped with all the loot!      *\n");
	ft_printf("  *     Final Movements: " YELLOW "%d"
		GREEN "                   *\n", ctx->movements);
	ft_printf("  *                                            *\n");
	ft_printf("  *     " CYAN "Thank you for playing so_long! 🐬"
		GREEN "       *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n" RESET);
	ft_printf("\n");
	destroy_ctx(ctx);
	exit(0);
}

void	error(char *msg, t_ctx *ctx)
{
	ft_printf(RED "\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("  #          " YELLOW "⚠️   ERROR OCCURRED  ⚠️"
		RED "           #\n");
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("    Reason: %s\n", msg);
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n" RESET);
	ft_printf("\n");
	if (ctx)
		destroy_ctx(ctx);
	exit(1);
}

int	win_destroy(t_ctx *ctx)
{
	success_exit(ctx);
	return (0);
}
