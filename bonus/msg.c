/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:55 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 19:19:47 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *msg, t_ctx *ctx)
{
	if (ctx)
	{
		if (ctx->map_alloc && ctx->map.map_matris)
			free_map(ctx);
		if (ctx->mlx_ptr)
		{
			if (ctx->win_ptr)
				mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
			mlx_destroy_display(ctx->mlx_ptr);
			free(ctx->mlx_ptr);
		}
		if (ctx->wall)
			free(ctx->wall);
		free(ctx);
	}
	ft_printf(RED "ERROR\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	congrats_msg(void)
{
	ft_printf(GREEN "\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     " YELLOW "🎉  CONGRATULATIONS!  🎉" GREEN "             *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n");
	ft_printf("  *                                            *\n");
	ft_printf("  *     You've conquered the dungeon!          *\n");
	ft_printf("  *     " CYAN "Thank you for playing so_long! 🐬" GREEN "       *\n");
	ft_printf("  *                                            *\n");
	ft_printf("  **********************************************\n" RESET);
	ft_printf("\n");
}

void	failed_msg(void)
{
	ft_printf(RED "\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("  #          " WHITE "☠️   GAME OVER  ☠️" RED "               #\n");
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n");
	ft_printf("  #                                            #\n");
	ft_printf("  #     The shadows have taken you...          #\n");
	ft_printf("  #     " YELLOW "Try again to claim your glory!" RED "      #\n");
	ft_printf("  #                                            #\n");
	ft_printf("  ##############################################\n" RESET);
	ft_printf("\n");
}
