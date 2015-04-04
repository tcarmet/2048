/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:02:14 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:02:15 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		wkw_make_move_x(t_all *all, int *i, int *j, t_pos pos)
{
	if (*i != pos.y
		&& all->map.tab[*j][pos.x] == all->map.tab[*i + all->dir.y][pos.x]
		&& all->map.tab_changes[*i + all->dir.y][pos.x] == 0)
	{
		if ((all->map.tab[*i + all->dir.y][pos.x] *= 2) == all->win_value)
			all->has_won = 1;
		all->map.tab_changes[*i + all->dir.y][pos.x] = 1;
		all->score += all->map.tab[*i + all->dir.y][pos.x];
		*i += all->dir.y;
	}
	else
		all->map.tab[*i][pos.x] = all->map.tab[*j][pos.x];
	all->map.tab[*j][pos.x] = 0;
}

static void		wkw_make_move_y(t_all *all, int *i, int *j, t_pos pos)
{
	if (*i != pos.x
		&& all->map.tab[pos.y][*j] == all->map.tab[pos.y][*i + all->dir.x]
		&& all->map.tab_changes[pos.y][*i + all->dir.x] == 0)
	{
		if ((all->map.tab[pos.y][*i + all->dir.x] *= 2) == all->win_value)
			all->has_won = 1;
		all->map.tab_changes[pos.y][*i + all->dir.x] = 1;
		all->score += all->map.tab[pos.y][*i + all->dir.x];
		*i += all->dir.x;
	}
	else
		all->map.tab[pos.y][*i] = all->map.tab[pos.y][*j];
	all->map.tab[pos.y][*j] = 0;
}

static int		move_block_x(t_all *all, t_pos pos)
{
	int	i;
	int j;
	int changed;

	changed = 0;
	i = pos.y;
	while ((all->dir.y > 0 && i >= 0) || (all->dir.y <= 0 && i < all->map.size))
	{
		if (all->map.tab[i][pos.x] == 0
			|| (i != pos.y
			&& all->map.tab[i][pos.x] == all->map.tab[i + all->dir.y][pos.x]))
		{
			j = i;
			while (wkw_tab_is_valid(j, pos.x, all) && VALUE_POS(pos.x, j) == 0)
				j -= all->dir.y;
			if (wkw_tab_is_valid(j, pos.x, all))
			{
				wkw_make_move_x(all, &i, &j, pos);
				changed = 1;
			}
		}
		i -= all->dir.y;
	}
	return (changed);
}

static int		move_block_y(t_all *all, t_pos pos)
{
	int	i;
	int j;
	int changed;

	changed = 0;
	i = pos.x;
	while ((all->dir.x > 0 && i >= 0) || (all->dir.x <= 0 && i < all->map.size))
	{
		if (all->map.tab[pos.y][i] == 0
			|| (i != pos.x
			&& all->map.tab[pos.y][i] == all->map.tab[pos.y][i + all->dir.x]))
		{
			j = i;
			while (wkw_tab_is_valid(pos.y, j, all) && VALUE_POS(j, pos.y) == 0)
				j -= all->dir.x;
			if (wkw_tab_is_valid(pos.y, j, all))
			{
				wkw_make_move_y(all, &i, &j, pos);
				changed = 1;
			}
		}
		i -= all->dir.x;
	}
	return (changed);
}

int				wkw_move(t_all *all)
{
	t_pos	pos;
	int		changed;

	changed = 0;
	if (all->dir.x != 0)
	{
		pos.y = 0;
		pos.x = (all->dir.x > 0 ? all->map.size - 1 : 0);
		while (pos.y < all->map.size)
		{
			if (move_block_y(all, pos) == 1)
				changed = 1;
			pos.y++;
		}
		return (changed);
	}
	pos.x = 0;
	pos.y = (all->dir.y > 0 ? all->map.size - 1 : 0);
	while (pos.x < all->map.size)
	{
		if (move_block_x(all, pos) == 1)
			changed = 1;
		pos.x++;
	}
	return (changed);
}
