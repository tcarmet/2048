/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_ncurses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:02:26 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:02:26 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	wkw_init_ncurses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	noecho();
	srand(time(NULL));
	if (has_colors() == FALSE)
		return (wkw_error(NO_COLORS));
	else
		start_color();
	return (STATUS_CONTINUE);
}
