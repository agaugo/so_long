/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:46:02 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/22 15:19:01 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

char	**allocate_map_memory(t_data *game, char **map, int col_i, char *line)
{
	if (game->map.map_height <= col_i)
	{
		map = resize(map, game->map.map_height, game->map.map_height + 1);
		game->map.map_height++;
	}
	map[col_i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!map[col_i])
		return (NULL);
	return (map);
}

void	parse_and_validate_line(t_data *game, char **map, char *line, int col_i)
{
	int	row_i;

	row_i = 0;
	while (line[row_i] != '\0' && line[row_i] != '\n')
	{
		if (line[row_i] == 'P')
		{
			game->player.x = row_i;
			game->player.y = col_i;
			game->map.validity.player_count++;
			map[col_i][row_i] = '0';
		}
		else
			map[col_i][row_i] = line[row_i];
		row_i++;
	}
	map[col_i][row_i] = '\0';
	row_i++;
	if (row_i != game->map.map_width && game->error == 1)
		game->error = 0;
}

void	save_lines(t_data *game)
{
	game->player.count = 0;
	game->map.validity.player_count = 0;
	game->map.map_height = 1;
}

void	save_lines_two(t_data *game, char **map)
{
	game->map.map_width--;
	game->map.map = map;
}

void	parse_map(int fd, t_data *game)
{
	char	**map;
	char	*line;
	int		col_i;

	col_i = 0;
	game->error = 1;
	save_lines(game);
	map = (char **)malloc(sizeof(char *) * (game->map.map_height + 1));
	if (!map)
		return ;
	line = get_next_line(fd);
	game->map.map_width = (int)ft_strlen(line);
	while (line)
	{
		map = allocate_map_memory(game, map, col_i, line);
		if (!map)
			return ;
		parse_and_validate_line(game, map, line, col_i);
		free(line);
		col_i++;
		line = get_next_line(fd);
	}
	save_lines_two(game, map);
	if (!read_map(game) || game->error == 0)
		invalid_map(game);
}
