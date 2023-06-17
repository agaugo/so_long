//
// Created by Hugo Flohil de Sousa on 16/06/2023.
//

#include "../include/so_long.h"

void	render_map(t_data *game)
{
    int	row_i;
    int	col_i;

    col_i = 0;
    game->map.validity.goblin_count = 0;
    game->map.validity.exit_count = 0;
    game->map.validity.player_count = 0;
    while (col_i < game->map.map_height)
    {
        row_i = 0;
        while (game->map.map[col_i][row_i] != '\0')
        {
            if (row_i == game->player.x && col_i == game->player.y)
                game->img = game->imgs.img_hero;
            else if (game->map.map[col_i][row_i] == '1')
                game->img = game->imgs.img_wall;
            else if (game->map.map[col_i][row_i] == '0')
                game->img = game->imgs.img_tile;
            else if (game->map.map[col_i][row_i] == 'C')
            {
                game->img = game->imgs.img_goblin;
                game->map.validity.goblin_count++;
            }
            else if (game->map.map[col_i][row_i] == 'E')
                game->img = game->imgs.img_exit;
            mlx_put_image_to_window(game->mlx, game->win, game->img, (row_i
                                                                      * IMG_SIZE), (col_i * IMG_SIZE));
            row_i++;
        }
        col_i++;
    }
}

void	load_imgs(t_data *game)
{
    int	null_w;
    int	null_h;

    game->imgs.img_tile = mlx_xpm_file_to_image(game->mlx,
                                                "./textures/tile.xpm", &null_w, &null_h);
    game->imgs.img_wall = mlx_xpm_file_to_image(game->mlx,
                                                "./textures/wall.xpm", &null_w, &null_h);
    game->imgs.img_hero = mlx_xpm_file_to_image(game->mlx,
                                                "./textures/hero.xpm", &null_w, &null_h);
    game->imgs.img_goblin = mlx_xpm_file_to_image(game->mlx,
                                                  "./textures/goblin.xpm", &null_w, &null_h);
    game->imgs.img_exit = mlx_xpm_file_to_image(game->mlx,
                                                "./textures/exit.xpm", &null_w, &null_h);
}
