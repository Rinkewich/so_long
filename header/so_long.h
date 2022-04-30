#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
typedef struct	s_game_map
{
    int     map_height;
    int     map_length;
    int     player_position_x;
    int     player_position_y;
    int     game_score;
    int     max_score;
    char    **map_data;
    int     game_over;
    int     steps;
    void    *end_img;
    void    *wall;
    void    *exit;
    void    *player;
    void    *floor;
    void    *items;
    void    *enemy;
    int     *enemypos;
}   t_game_map;

typedef struct	s_render_v {
    void    *mlx;
    void    *win;
}   t_render_v;

enum	e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};
void		get_map(int argc, char **argv, t_game_map *map);
int			get_filename(char *argv);
void		error(char *error_code);
#endif