/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:15 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:07:17 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_cmd_args(int argc, char const *argv[], t_ctx *ctx)
{
	int	map_len;

	if (argc < 2)
		error("Please Enter a map!", ctx);
	if (argc > 2)
		error("You entered alot of argument.", ctx);
	map_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		error("Map file is not valid. You can enter just .ber file.", \
		ctx);
}
