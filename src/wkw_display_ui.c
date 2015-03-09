/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_display_ui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:59:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 20:59:54 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		display_edges(t_all *all)
{
	int i;

	attron(COLOR_PAIR(100));
	i = 0;
	while (i < all->row)
	{
		mvprintw(i, 0, " ");
		mvprintw(i, all->col - 1, " ");
		i++;
	}
	i = 0;
	while (i < all->col)
	{
		mvprintw(0, i, " ");
		mvprintw(all->row - 1, i, " ");
		i++;
	}
}

static void		display_xgrid(t_all *all)
{
	int sizegrid;
	int x;
	int y;
	int i;

	i = 0;
	sizegrid = all->map.width / all->map.size;
	x = sizegrid;
	while (i < all->map.size - 1)
	{
		y = 0;
		while (y < (all->map.height / all->map.size) * all->map.size)
		{
			mvprintw(y, x, " ");
			y++;
		}
		x += sizegrid;
		i++;
	}
}

static void		display_ygrid(t_all *all)
{
	int sizegrid;
	int x;
	int y;
	int i;

	i = 0;
	sizegrid = all->map.height / all->map.size;
	x = sizegrid;
	while (i < all->map.size)
	{
		y = 0;
		while (y < all->map.width)
		{
			mvprintw(x, y, " ");
			y++;
		}
		x += sizegrid;
		i++;
	}
	attroff(COLOR_PAIR(100));
}

static void		wkw_display_warning_window_size(t_all *all)
{
	while (1)
	{
		getmaxyx(stdscr, all->row, all->col);
		all->map.width = all->col;
		all->map.height = all->row - MENU_HEIGHT;
		all->map.blockw = all->map.width / all->map.size;
		all->map.blockh = all->map.height / all->map.size;
		if (all->row >= all->min_width && all->col >= all->min_height)
			break ;
		clear();
		wkw_display_panel(all, INVALID_WINDOW_SIZE);
		getch();
	}
}

int				wkw_display_ui(t_all *all)
{
	int	status;

	clear();
	getmaxyx(stdscr, all->row, all->col);
	all->map.width = all->col;
	all->map.height = ((all->row - MENU_HEIGHT) / all->map.size)
		* all->map.size;
	all->map.blockw = all->map.width / all->map.size;
	all->map.blockh = all->map.height / all->map.size;
	if (all->col < all->min_width || all->row < all->min_height)
		wkw_display_warning_window_size(all);
	display_edges(all);
	display_xgrid(all);
	display_ygrid(all);
	wkw_display_numbers(all);
	wkw_display_menu(all);
	if (all->has_already_won == 0 && all->has_won == 1)
	{
		all->has_already_won = 1;
		if ((status = wkw_display_panel(all, YOU_WIN)) != STATUS_CONTINUE)
			return (status);
		wkw_display_ui(all);
	}
	refresh();
	return (STATUS_CONTINUE);
}
