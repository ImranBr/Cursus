/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:46:39 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/04/25 20:22:28 by ibarbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 640

/* Codes clavier */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

/* Indices des textures */
# define FLOOR 0
# define WALL 1
# define COLLECTIBLE 2
# define EXIT 3
# define PLAYER 4

typedef struct s_data
{
	char		**map;
	char		**map_copy;
	char		*av;
	int			x;
	int			y;
	char		*line;
	int			nbline;
	int			fd;
}				t_data;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*window;
	void		**textures;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			tile_size;
}				t_mlx;

typedef struct s_render
{
	int			x;
	int			y;
	int			pixel_x;
	int			pixel_y;
}				t_render;

typedef struct s_game
{
	t_data		data;
	t_mlx		mlx;
	t_render	render;
	int			moves;
	int			collectibles;
}				t_game;

/* get_next_line.c */
char			*get_next_line(int fd);

/* flood_fill.c */
int				check_after_flood(t_data *data);
int				find_player(t_data *data);
void			flood_fill(t_data *data);
void			fill(t_data *data, int x, int y);

/* map_parsing.c */
int				is_rectangular(t_data *data);
int				is_outline_1(t_data *data);
int				check_char(t_data *data);

/* map_utils.c */
int				check_side(t_data *data);
int				check_top_bottom(t_data *data);
int				check_valid_char(t_data *data, int *p_count, int *c_count,
					int *e_count);
int				check_count_char(int p_count, int e_count, int c_count);
int				copy_map(t_data *data);

/* utils.c */
void			free_map(char **map);
void			print_map(char **map);
int				count_line(char *av);

/* main.c */
int				init(t_data *data, char *av);
int				parse_map(t_data *data);

/* mlx_utils.c */
void			free_mlx(t_mlx *mlx);
int				init_mlx(t_mlx *mlx, t_data *data);
int				load_textures(t_mlx *mlx);
void			render_map(t_mlx *mlx, t_data *data, t_render *render);
int				key_hook(int keycode, void *param);
int				close_window(void *param);

/* game.c */
int				init_game(t_game *game, char *map_path);
int				count_collectibles(t_data *data);
void			move_player(t_game *game, int dx, int dy);
int				game_loop(void *param);

#endif
