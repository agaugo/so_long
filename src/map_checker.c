
/*

needs to check:

- contains 1 exit, at least 1 collectible, and 1 starting position
- map is rectangular
- map is surrounded by walls (closed)
- must have a valid path to collectibles and exit

*/

#include "../so_long.h"

// int	flood_fill(t_data *game)
// {

// }

int	check_map(t_data *game)
{
	if (game->map.validity.player_count != 1 ||
		game->map.validity.goblin_count < 1 ||
		game->map.validity.exit_count != 1)
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