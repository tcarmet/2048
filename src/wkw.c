/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:58:11 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/05 01:19:54 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		wkw_key_hook(t_all *all)
{
	int		ch;

	ch = getch();
	all->dir.y = 0;
	all->dir.x = 0;
	if (ch == KEY_UP || ch == KEY_DOWN)
		all->dir.y = (ch == KEY_UP ? -1 : 1);
	else if (ch == KEY_RIGHT || ch == KEY_LEFT)
		all->dir.x = (ch == KEY_RIGHT ? 1 : -1);
	else if (ch == KEY_RESIZE)
		wkw_wait();
	else if (ch == KEY_ECHAP || ch == KEY_Q)
		return (STATUS_EXIT);
	else if (ch == KEY_F(1))
		return (RESET_GAME);
	if (all->dir.x != 0 || all->dir.y != 0)
	{
		wkw_reinit_changes(all);
		if (wkw_move(all) == 1)
			wkw_gen_new_number(all);
		else
			ft_putchar(7);
	}
	return (STATUS_CONTINUE);
}

static void		wkw_getch_loop(t_all *all)
{
	int status;

	while (1)
	{
		status = wkw_key_hook(all);
		if (status == STATUS_EXIT)
			break ;
		else if (status == RESET_GAME)
			wkw_reinit(all);
		if (wkw_display_ui(all) == STATUS_EXIT)
			break ;
		if (wkw_empty_check(all) == 0)
			if (wkw_game_over(all) != STATUS_CONTINUE)
				break ;
	}
}

static void		wkw_init_pair(void)
{
	init_pair(1, COLOR_BLACK, 45);
	init_pair(2, COLOR_BLACK, 44);
	init_pair(3, COLOR_BLACK, 43);
	init_pair(4, COLOR_BLACK, 42);
	init_pair(5, COLOR_BLACK, 41);
	init_pair(6, COLOR_BLACK, 40);
	init_pair(7, COLOR_BLACK, 183);
	init_pair(8, COLOR_BLACK, 182);
	init_pair(9, COLOR_BLACK, 181);
	init_pair(10, COLOR_BLACK, 180);
	init_pair(11, COLOR_BLACK, 179);
	init_pair(12, COLOR_BLACK, 178);
	init_pair(13, COLOR_BLACK, 172);
	init_pair(14, COLOR_BLACK, 166);
	init_pair(15, COLOR_BLACK, 160);
	init_pair(16, COLOR_WHITE, 93);
	init_pair(17, COLOR_WHITE, 92);
	init_pair(18, COLOR_WHITE, 91);
	init_pair(19, COLOR_WHITE, 90);
	init_pair(20, COLOR_WHITE, 89);
	init_pair(21, COLOR_WHITE, 88);
	init_pair(100, COLOR_WHITE, 237);
	init_pair(101, COLOR_WHITE, 235);
	init_pair(200, COLOR_WHITE, COLOR_RED);
	init_pair(201, COLOR_BLACK, COLOR_GREEN);
}

int				main(int argc, char **argv)
{
	t_all all;

	if (wkw_check_argv(&all, argc, argv) != STATUS_CONTINUE)
		return (1);
	if (wkw_init_map(&all, all.map.size) != STATUS_CONTINUE)
		return (1);
	if (wkw_init_ncurses() != STATUS_CONTINUE)
		return (1);
	wkw_init_pair();
	wkw_display_ui(&all);
	wkw_getch_loop(&all);
	endwin();
	return (0);
}
