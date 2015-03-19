/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_display_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:59:02 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/19 15:12:09 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		wkw_display_controls(t_all *all)
{
	char		*str;

	str = "NEW GAME: F1  -  QUIT: ESC / Q  -  PLAY: ARROW KEYS";
	mvprintw(all->row - 4, all->col / 2 - 25, str);
}

static void		wkw_display_menu_bg(t_all *all)
{
	int	i;
	int	j;

	attron(COLOR_PAIR(101));
	j = all->map.height + 1;
	while (j < all->row - 1)
	{
		i = 1;
		while (i < all->col - 1)
		{
			mvprintw(j, i, " ");
			i++;
		}
		j++;
	}
	attroff(COLOR_PAIR(101));
}

void			wkw_display_menu(t_all *all)
{
	char		*str1;
	char		*str2;

	wkw_display_menu_bg(all);
	wkw_display_controls(all);
	if (all->has_won == 1)
		mvprintw(all->row - 2, 2, "CONGRATULATIONS! YOU WON");
	if ((str1 = ft_itoa(all->score)))
	{
		if ((str2 = ft_strjoin("SCORE: ", str1)))
		{
			mvprintw(all->row - 2, all->col - 2 - ft_strlen(str2), str2);
			free(str2);
		}
		free(str1);
	}
}
