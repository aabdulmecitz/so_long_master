/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:33:05 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 03:59:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map_file(int map_fd, int *rows, t_ctx *ctx)
{
	char	*map_temp;
	char	*line_temp;
	char	*tmp;

	map_temp = ft_strdup("");
	if (!map_temp)
		error("Map allocation failed.", ctx);
	*rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		tmp = ft_strjoin(map_temp, line_temp);
		free(map_temp);
		free(line_temp);
		map_temp = tmp;
		(*rows)++;
	}
	return (map_temp);
}

void	check_cmd_args(int argc, char const *argv[], t_ctx *ctx)
{
	int	map_len;

	if (argc < 2)
		error("Please Enter a map!", ctx);
	if (argc > 2)
		error("You entered too many arguments.", ctx);
	map_len = ft_strlen(argv[1]);
	if (map_len < 5 || !ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		error("Map file is not valid. It must be a .ber file.", ctx);
}

void	check_empty_lines(char *map, t_ctx *ctx)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error("Invalid map: empty line at the beginning.", ctx);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error("Invalid map: empty line at the end.", ctx);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error("Invalid map: empty line in the middle.", ctx);
		}
		i++;
	}
}

void	map_initializer(t_ctx *ctx, char *argv)
{
	char	*map_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error("The Map couldn't be opened. Does the Map exist?", ctx);
	map_temp = read_map_file(map_fd, &ctx->map.rows, ctx);
	close(map_fd);
	check_empty_lines(map_temp, ctx);
	ctx->map.map_matris = ft_split(map_temp, '\n');
	if (!ctx->map.map_matris)
	{
		free(map_temp);
		error("Map split failed.", ctx);
	}
	gc_add_string_array(&ctx->gc, ctx->map.map_matris);
	ctx->map_alloc = 1;
	free(map_temp);
}
