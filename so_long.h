#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
// **** STRUCTS **** //

# define IMG_SIZE 32

typedef struct s_player {
	int	x;
	int	y;
} t_player;

typedef	struct s_map {
	int		map_height;
	int		map_width;
	char	**map;
} t_map;

typedef struct s_imgs {
	void		*img_tile;
	void		*img_wall;
	void		*img_hero;
	void		*img_goblin;
	void		*img_exit;
} t_imgs;

typedef	struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	t_imgs		imgs;
	t_map		map;
	t_player	player;
}	t_data;

//  **** CORE **** //

int		main(int argc, char *argv[]);
void	parse_map(int fd, t_data *game, int win_width, int win_height);
void	player_move(int fd, t_data *game);
int	key_hook(int keycode, t_data *game);
// int	key_hook(int keycode, t_data *game__attribute__((unused)));
int		ft_strcmp(const char *str1, const char *str2);
void	free_game(t_data *game);
void print2DArray(t_data *game);


#endif