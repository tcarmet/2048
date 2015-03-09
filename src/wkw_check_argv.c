/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_check_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:58:19 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 20:58:30 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	wkw_check_power(int win_value)
{
	int i;

	if (win_value < 0)
		return (INVALID_WIN_VALUE_NEG);
	i = 2;
	while (i <= win_value)
	{
		if (i == win_value)
			return (STATUS_CONTINUE);
		i *= 2;
	}
	return (INVALID_WIN_VALUE);
}

int			wkw_check_argv(t_all *all, int argc, char **argv)
{
	int status;

	all->map.size = MAP_SIZE;
	all->win_value = WIN_VALUE;
	all->has_already_won = 0;
	all->has_won = 0;
	all->score = 0;
	if (argc > 1)
		all->map.size = ft_atoi(argv[1]);
	if (all->map.size < 2)
		return (wkw_error(INVALID_SIZE_TOO_SHORT));
	else if (all->map.size > 5)
		return (wkw_error(INVALID_SIZE_TOO_BIG));
	if (argc > 2)
		all->win_value = ft_atoi(argv[2]);
	if ((status = wkw_check_power(all->win_value)) != STATUS_CONTINUE)
		return (wkw_error(status));
	all->min_width = (all->map.size * (6 + 1) + 1);
	all->min_height = (all->map.size * (1 + 1) + 1 + MENU_HEIGHT);
	return (STATUS_CONTINUE);
}
