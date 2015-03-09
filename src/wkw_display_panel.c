/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_display_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:59:39 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 20:59:40 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	wkw_display_panel_bg(t_all *all)
{
	int	panel_width;
	int	panel_x;
	int	panel_y;
	int	i;
	int	j;

	panel_width = 60 * all->map.width / 100;
	panel_x = (all->col - panel_width) / 2;
	panel_y = (all->row - 5) / 2;
	j = panel_y;
	while (j < panel_y + 5)
	{
		i = panel_x;
		while (i < panel_x + panel_width)
		{
			mvprintw(j, i, " ");
			i++;
		}
		j++;
	}
}

static void	wkw_display_panel_fg1(t_all *all, int type)
{
	int		str_x;
	int		str_y;
	char	*str;

	if (type == GAME_OVER)
		str = "GAME OVER";
	else if (type == INVALID_WINDOW_SIZE)
		str = "WINDOW TOO SMALL";
	else
		str = "YOU WIN!";
	str_x = (all->col / 2) - (ft_strlen(str) / 2);
	str_y = (all->row - 5) / 2 + 1;
	mvprintw(str_y, str_x, str);
}

static void	wkw_display_panel_fg2(t_all *all, int type)
{
	int		str_x;
	int		str_y;
	char	*str1;
	char	*str2;

	if (type == GAME_OVER)
	{
		str1 = "PRESS F2 TO PLAY A NEW GAME";
		str2 = "OR PRESS ECHAP TO EXIT";
	}
	else if (type == YOU_WIN)
	{
		str1 = "PRESS F2 TO CONTINUE";
		str2 = "OR PRESS ECHAP TO EXIT";
	}
	else
	{
		str1 = "PLEASE RESIZE";
		str2 = "YOUR TERMINAL SCREEN";
	}
	str_x = (all->col / 2) - (ft_strlen(str1) / 2);
	str_y = (all->row - 5) / 2 + 2;
	mvprintw(str_y, str_x, str1);
	str_x = (all->col / 2) - (ft_strlen(str2) / 2);
	mvprintw(str_y + 1, str_x, str2);
}

int			wkw_display_panel(t_all *all, int type)
{
	int ch;

	while (1)
	{
		attron(COLOR_PAIR(type == YOU_WIN ? 201 : 200));
		wkw_display_panel_bg(all);
		wkw_display_panel_fg1(all, type);
		wkw_display_panel_fg2(all, type);
		attroff(COLOR_PAIR(type == YOU_WIN ? 201 : 200));
		refresh();
		if (type == INVALID_WINDOW_SIZE)
			break ;
		ch = getch();
		if (ch == KEY_ECHAP || ch == KEY_Q)
			return (STATUS_EXIT);
		else if (ch == KEY_F(2))
			return (STATUS_CONTINUE);
		if (wkw_display_ui(all) == STATUS_EXIT)
			return (STATUS_EXIT);
	}
	return (STATUS_CONTINUE);
}
