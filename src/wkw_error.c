/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:01:20 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:01:20 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	wkw_error(int er)
{
	endwin();
	if (er == NO_COLORS)
		ft_putendl_fd("Your terminal don't support colors", STDERR);
	else if (er == INVALID_SIZE_TOO_SHORT)
		ft_putendl_fd("Map size too short", STDERR);
	else if (er == INVALID_SIZE_TOO_BIG)
		ft_putendl_fd("Map size too big", STDERR);
	else if (er == INVALID_WIN_VALUE)
		ft_putendl_fd("Win value is not a power of 2", STDERR);
	else if (er == INVALID_WIN_VALUE_NEG)
		ft_putendl_fd("Win value should be a positive value", STDERR);
	else if (er == INVALID_WINDOW_SIZE)
	{
		ft_putendl_fd("Window size became too small", STDERR);
		return (STATUS_EXIT);
	}
	ft_putendl_fd("usage: ./game_2048 [map size [win value]]", STDERR);
	return (er);
}
