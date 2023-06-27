/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:13:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/06/27 23:26:46 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include "libft-plus/libft/libft.h"
# include "libft-plus/printf/ft_printf.h"
# include "libft-plus/get-next-line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>

# define WINDOW_X_SIZE 1920
# define WINDOW_Y_SIZE 1080

# define S_PLAYER "./assets/player.xpm"
# define S_PLAYER_BIS "./assets/player_bis.xpm"
# define S_PLAYER_HAPPY "./assets/player_happy.xpm"
# define S_WALL "./assets/wall.xpm"
# define S_ITEM "./assets/item.xpm"
# define S_EXIT "./assets/exit.xpm"
# define S_EMPTY "./assets/empty.xpm"
# define S_P_EXIT "./assets/player_on_exit.xpm"

# define E_ROW "Error\nLe nombre de ligne est-il correcte ?\n"
# define E_TYPE "Error\nUn caractère étrange s'est glissé dans la map !\n"
# define E_EXIT "Error\nTrop ou pas assez de sorties, on va pas s'en \
s'en sortir là !!! \
\nAssurez-vous qu'il n'y ai qu'un seul 'E'\n"
# define E_PLAYER "Error\nGalère avec le joueur !\n"
# define E_START "Error\nLe joueur ne peut pas être à plus d'un endroit \
à la fois !!! \
\nAssurez vous qu'il n'y ai qu'un seul 'P'\n"
# define E_ITEMS "Error\nSans items à collecter, le jours va s'ennuyer !\n \
Ajoutez au moins un objet à collecter dans la map, avec 'C'\n"
# define E_NCLOSE "Error\nLa map n'est pas correctement fermée !!!\n"
# define E_WAYS "Error\nIl n'y a aucun chemin valide, c'est pas sympa pour \
le perso !\n"
# define WIN "\nBilal est au calme entouré de chat et de crêpes. Le paradis ! \
\nEt en un nombre impressionnant de mouvements !! %d\n\n"
# define E_BER "\nError\nOn n'est un peu pointilleux chez nous, les cartes doivent \
être en .ber!\n\n"
# define W_TITLE "Help Bilal to catch the cats and eat the final crepe ! !\n"
# define NB_MOVE "Nombre de mouvements : %d\n"

typedef struct s_sprite {
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_point {
	int				x;
	int				y;
	char			type;
	struct s_point	*up;
	struct s_point	*dw;
	struct s_point	*lf;
	struct s_point	*rg;
	struct s_point	*next;
	int				tmp;
}	t_point;

typedef struct s_canva {
	void		*mlx;
	void		*window;
	int			nb_items;
	int			ll;
	int			nb_l;
	int			x_off;
	int			y_off;
	int			player_x;
	int			player_y;
	int			nb_move;
	int			is_happy;
	char		*map_name;
	t_sprite	player;
	t_sprite	player_bis;
	t_sprite	player_happy;
	t_sprite	wall;
	t_sprite	item;
	t_sprite	exit;
	t_sprite	empty;
	t_sprite	p_exit;
	t_point		*map_first;
	t_point		*map_player;
	t_point		*map_end;
	t_point		*map_exit;
	t_point		**map_items;
}		t_canva;

int		ft_create_trgb(int t, int r, int g, int b);
int		ft_create_trgb(int t, int r, int g, int b);
int		ft_create_map(t_canva *canva);
void	ft_display_map(t_canva *canva);
int		ft_line_in_list(t_canva *canva, char *line);
int		ft_destroy_map(t_canva *canva);
int		ft_add_point(t_canva *canva, char type);
int		ft_init(t_canva *canva, int ac, char **av);
int		ft_add_horizontal(t_canva *canva);
t_point	*ft_found_down(t_point *point);
int		ft_add_vertical(t_canva *canva);
int		ft_verify_line_len(t_canva *canva);
int		ft_verify_map(t_canva *canva);
int		ft_verify_auth_char(t_canva *canva);
int		ft_type_exist(char c);
int		ft_verify_one_exit(t_canva *canva);
int		ft_verify_one_start(t_canva *canva);
int		ft_verify_items(t_canva *canva);
int		ft_verify_map_close(t_canva *canva);
int		ft_verify_is_wall(t_point *point);
int		ft_verify_map_close2(t_point *browse);
int		ft_register_map_items(t_canva *canva, int nb_items);
int		ft_verify_items(t_canva *canva);
int		ft_valid_way(t_canva *canva, t_point *a, t_point *b);
int		ft_check_ways(t_canva *canva, t_point *a, t_point *b);
int		ft_check_valid_tile(t_point *point);
int		ft_valid_items_way(t_canva *canva);
int		ft_make_canva(t_canva *canva);
int		ft_create_sprites(t_canva *canva);
int		ft_create_maze(t_canva *canva);
int		ft_keyboard_action(int keycode, t_canva *canva);
int		ft_move_right(t_canva *canva);
int		ft_move_left(t_canva *canva);
int		ft_move_up(t_canva *canva);
int		ft_move_down(t_canva *canva);
int		ft_replace_by_empty(t_canva *canva, t_point *tile);
int		ft_replace_by_player(t_canva *canva, t_point *tile);
int		ft_stop_program(t_canva *canva);
int		ft_adjust_screen_x(t_canva *canva);
int		ft_keep_player_in_map(t_canva *canva);
int		ft_adjust_screen_y(t_canva *canva);
int		ft_display_player(t_canva *canva, t_point *tile);
int		ft_calculate_screen(t_canva *canva);
int		ft_verify_ber(char *name);
int		ft_verify_one_player(t_canva *canva);

#endif
