/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_check_gameplay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:58:46 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 20:58:47 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	wkw_check_move(t_all *all)
{
	int i;
	int j;

	j = 0;
	while (j < all->map.size)
	{
		i = 0;
		while (i < all->map.size)
		{
			if (j > 0 && all->map.tab[i][j] == all->map.tab[i][j - 1])
				return (1);
			if (j < all->map.size - 1
				&& all->map.tab[i][j] == all->map.tab[i][j + 1])
				return (1);
			if (i > 0 && all->map.tab[i][j] == all->map.tab[i - 1][j])
				return (1);
			if (i < all->map.size - 1
				&& all->map.tab[i][j] == all->map.tab[i + 1][j])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int			wkw_empty_check(t_all *all)
{
	int i;
	int j;

	j = 0;
	while (j < all->map.size)
	{
		i = 0;
		while (i < all->map.size)
		{
			if (all->map.tab[i][j] == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (wkw_check_move(all));
}
