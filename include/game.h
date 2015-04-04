/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:57:12 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/04 17:43:44 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>
# include <fcntl.h>
# include <strings.h>
# include "time.h"
# define KEY_Q 113
# define KEY_ECHAP 27
# define MAP_SIZE 4
# define CURENT_POS all->map.tab[pos.y][pos.x]
# define NEXT_POS all->map.tab[pos.y + dir.y][pos.x + dir.x]
# define VALUE_POS(x, y) all->map.tab[y][x]
# define MENU_HEIGHT 5
# define STDERR 2
# define COLOR_MAX 21

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef enum	e_er
{
	STATUS_EXIT,
	STATUS_CONTINUE,
	RESET_GAME,
	NO_COLORS,
	SYSCALL,
	INVALID_SIZE_TOO_SHORT,
	INVALID_SIZE_TOO_BIG,
	INVALID_WIN_VALUE,
	INVALID_WIN_VALUE_NEG,
	GAME_OVER,
	YOU_WIN,
	INVALID_WINDOW_SIZE
}				t_er;

typedef struct	s_map
{
	int			**tab;
	int			**tab_changes;
	int			size;
	int			height;
	int			width;
	int			blockw;
	int			blockh;
}				t_map;

typedef struct	s_all
{
	t_pos		dir;
	t_map		map;
	int			row;
	int			col;
	int			min_width;
	int			min_height;
	int			score;
	int			has_won;
	int			has_already_won;
	int			win_value;
}				t_all;

int				wkw_display_ui(t_all *all);
void			wkw_display_numbers(t_all *all);
int				wkw_init_ncurses(void);
int				wkw_init_map(t_all *all, int size);
void			wkw_reinit(t_all *all);
int				wkw_move(t_all *all);
int				wkw_error(int er);
void			wkw_wait(void);
void			wkw_wait_time(void);
int				wkw_tab_is_valid(int y, int x, t_all *all);
int				wkw_empty_check(t_all *all);
int				wkw_game_over(t_all *all);
int				wkw_check_argv(t_all *all, int argc, char **argv);
void			wkw_gen_new_number(t_all *all);
void			wkw_display_menu(t_all *all);
int				ft_rand_a_b(int a, int b);
int				wkw_display_panel(t_all *all, int type);
void			wkw_reinit_changes(t_all *all);
size_t			ft_strlen(char const *str);
void			ft_putchar(char c);
void			ft_putendl(char *str, int fd);
int				ft_atoi(char const *str);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putendl_fd(char *str, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
#endif
