/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:10:56 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/22 14:43:55 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_border(t_data *game)
{
    int i;

    i = 0;

    while (i < game->map.map_width)
    {
        if (game->map.map[0][i] != '1' || game->map.map[game->map.map_height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < game->map.map_height)
    {
        if (game->map.map[i][0] != '1' || game->map.map[i][game->map.map_width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

char	**copy_map(t_data *game)
{
	int		y;
	int		x;
	char	**map;

	map = (char **)malloc(sizeof(char *) * game->map.map_height + 1);
	if (!map)
		return (NULL);
	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		map[y] = (char *)malloc(sizeof(char) * game->map.map_width + 1);
		while (x < game->map.map_width)
		{
			map[y][x] = game->map.map[y][x];
			x++;
		}
		y++;
	}
	return (map);
}

void	flood_fill(t_data *game, char **map, int y, int x)
{
    if (y < 0 || y >= game->map.map_height || x < 0 || x >= game->map.map_width
        || game->map.map[y][x] == '1')
        return ;
    if (map[y][x] == 'V' || map[y][x] == 'E')
        return ;
    map[y][x] = 'V';
    flood_fill(game, map, y + 1, x);
    flood_fill(game, map, y - 1, x);
    flood_fill(game, map, y, x + 1);
    flood_fill(game, map, y, x - 1);
}

int check_path(t_data *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	flood_fill(game, map, game->player.y, game->player.x);
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
            printf("%c", map[y][x]);
			if (map[y][x] == 'C')
				return (0);
            else if (map[y][x] == 'E')
            {
                if (map[y][x + 1] != 'V' && map[y][x - 1] != 'V' && map[y + 1][x] != 'V' && map[y - 1][x])
                    return (0);
            }
			x++;
		}
        printf("\n");
		y++;
	}
	return (1);
}

int	check_map(t_data *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	if (game->map.validity.player_count != 1
		|| game->map.validity.goblin_count < 1
		|| game->map.validity.exit_count != 1
        || game->map.validity.alien_chars != 0)
		return (0);
	if (!check_path(game, map_copy))
		return (0);
    if (!check_border(game))
        return (0);
	return (1);
}

int	read_map(t_data *game)
{
	int	mh;
	int	mw;

	mh = 0;
	game->map.validity.goblin_count = 0;
	game->map.validity.exit_count = 0;
    game->map.validity.alien_chars = 0;
	while (mh < game->map.map_height)
	{
		mw = 0;
		while (mw < game->map.map_width)
		{
			if (game->map.map[mh][mw] == 'E')
				game->map.validity.exit_count++;
			else if (game->map.map[mh][mw] == 'C')
				game->map.validity.goblin_count++;
            else if (game->map.map[mh][mw] != '1' && game->map.map[mh][mw] != 'C' &&
                    game->map.map[mh][mw] != 'P' && game->map.map[mh][mw] != 'E' &&
                    game->map.map[mh][mw] != '0')
                game->map.validity.alien_chars++;
			mw++;
		}
		mh++;
	}
	return (check_map(game));
}
