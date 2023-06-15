#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_game(game);
		exit(0);
	}
	if (keycode == 13)		//up
		handle_movement(game, 1);
	if (keycode == 0)		//left
		handle_movement(game, 2);
	if (keycode == 1)		//down
		handle_movement(game, 3);
	if (keycode == 2)		//right
		handle_movement(game, 4);
	return (0);
}