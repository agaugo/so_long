#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

//because void param is unused we put __attribute__((unused))
//frees all info if esc is pressed.

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
	{
		mlx_destroy_image(game->mlx, game->imgs.img_wall);
		mlx_destroy_image(game->mlx, game->imgs.img_tile);
		mlx_destroy_image(game->mlx, game->imgs.img_goblin);
		mlx_destroy_image(game->mlx, game->imgs.img_exit);
		mlx_destroy_image(game->mlx, game->imgs.img_hero);
		free_game(game);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 119)		//up
		return (1);
	if (keycode == 97)		//left
		return (2);
	if (keycode == 115)		//down
		return (3);
	if (keycode == 100)		//right
		return (4);
	return (0);
}