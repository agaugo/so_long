/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:10:56 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/16 15:31:26 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

needs to check:

- contains 1 exit, at least 1 collectible, and 1 starting position
- map is rectangular
- map is surrounded by walls (closed)
- must have a valid path to collectibles and exit

*/

#include "../include/so_long.h"

void flood_fill(t_data *game, char **map, int y, int x)
{
    if (y < 0 || y >= game->map.map_height || x < 0 || x >= game->map.map_width || game->map.map[y][x] == '1')
        return ;
    if (map[y][x] == 'V')
        return ;
    map[y][x] = 'V';
    flood_fill(game, map, y + 1, x);
    flood_fill(game, map, y - 1, x);
    flood_fill(game, map, y, x + 1);
    flood_fill(game, map, y, x - 1);
}

char    **copy_map(t_data *game)
{
    int y;
    int x;
    char    **map;

    map = (char **)malloc(sizeof(char *) * game->map.map_height + 1);
    if (!map)
        return NULL;
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

int check_path(t_data *game, char **map)
{
    int y;
    int x;

    y = 0;
    x = 0;
    flood_fill(game, map, game->player.y, game->player.x);
    while (y < game->map.map_height)
    {
        x = 0;
        while (x < game->map.map_width)
        {
            if (map[y][x] == 'C' || map[y][x] == 'E')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int	check_map(t_data *game)
{
    char    **map_copy;

    map_copy = copy_map(game);
    if (game->map.validity.player_count != 1
		    || game->map.validity.goblin_count < 1
		    || game->map.validity.exit_count != 1)
        return (0);
    if (!check_path(game, map_copy))
        return (0);
	return (1);
}

int	read_map(t_data *game)
{
	int mh;
	int mw;

	mh = 0;
	game->map.validity.goblin_count = 0;
	game->map.validity.exit_count = 0;
	while (mh < game->map.map_height)
	{
		mw = 0;
		while (mw < game->map.map_width)
		{
			if (game->map.map[mh][mw] == 'E')
				game->map.validity.exit_count++;
			else if (game->map.map[mh][mw] == 'C')
				game->map.validity.goblin_count++;
			mw++;
		}
		mh++;
	}
	return (check_map(game));
}
