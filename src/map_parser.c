
#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

//refactored versions
char **allocate_map_memory(t_data *game, char **map, int col_i)
{
    if (game->map.map_height <= col_i)
    {
        map = resize(map, game->map.map_height, game->map.map_height + 1);
        game->map.map_height++;
    }
    map[col_i] = (char *) malloc(sizeof(char) * (game->map.map_width + 1));
    if (!map[col_i])
        return NULL;
    return map;
}

int parse_and_validate_line(t_data *game, char **map, char *line, int col_i)
{
    int row_i = 0;
    int error = 1;
    while (line[row_i] != '\0' && line[row_i] != '\n') {
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
    if (row_i != game->map.map_width)
        error = 0;
    return error;
}

void parse_map(int fd, t_data *game)
{
    char **map;
    char *line;
    int col_i = 0;
    int error = 1;

    game->player.count = 0;
    game->map.validity.player_count = 0;
    game->map.map_height = 1;
    map = (char **) malloc(sizeof(char *) * (game->map.map_height + 1));
    if (!map)
        return;
    line = get_next_line(fd);
    game->map.map_width = (int) ft_strlen(line);
    while (line)
    {
        map = allocate_map_memory(game, map, col_i);
        if (!map)
            return ;
        error = parse_and_validate_line(game, map, line, col_i);
        free(line);
        col_i++;
        line = get_next_line(fd);
    }
    game->map.map_width--;
    game->map.map = map;
    if (!read_map(game) || error == 0)
        invalid_map(game);
}




/*
old version:

void parse_map(int fd, t_data *game) {
    char **map;
    char *line;
    int row_i;
    int col_i;
    int error;

    error = 1;
    game->player.count = 0;
    game->map.validity.player_count = 0;
    game->map.map_height = 1;
    map = (char **) malloc(sizeof(char *) * (game->map.map_height + 1));
    if (!map)
        return;
    col_i = 0;
    line = get_next_line(fd);
    game->map.map_width = (int) ft_strlen(line);
    while (line)
    {
        if (game->map.map_height <= col_i)
        {
            map = resize(map, game->map.map_height, game->map.map_height + 1);
            game->map.map_height++;
        }
        row_i = 0;
        map[col_i] = (char *) malloc(sizeof(char) * (game->map.map_width + 3));
        if (!map[col_i])
            return ;
        read_line(game, line, col_i);
        while (line[row_i] != '\0' && line[row_i] != '\n') {
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
        if (row_i + 1 != game->map.map_width)
            error = 0;
        free(line);
        col_i++;
        line = get_next_line(fd);
    }
    game->map.map_width--;
    game->map.map = map;
    if (!read_map(game) || error == 0)
        invalid_map(game);
}

*/