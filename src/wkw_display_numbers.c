/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_display_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 20:59:29 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/28 18:15:33 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void			wkw_display_number_str(t_all *all, int block_x,
						int block_y, char *str)
{
	int		len;

	len = ft_strlen(str);
	mvprintw(block_y + ((all->map.height / all->map.size) / 2),
		block_x + ((all->map.width / all->map.size) / 2) - (len / 2),
		str);
}

static void			wkw_display_number_x(t_all *all, int x,
						int y, int j)
{
	int	block_x;
	int	block_y;
	int	i;

	block_x = x * (all->map.width / all->map.size);
	block_y = y * (all->map.height / all->map.size);
	i = block_x + 1;
	while (i < block_x + all->map.blockw)
	{
		if (all->map.tab_changes[y][x] == 1)
		{
			if ((i == block_x + 3 && j == block_y + 2)
				|| (i == block_x + 3 && j == block_y + all->map.blockh - 2)
				|| (j == block_y + 2 && i == block_x + all->map.blockw - 3)
				|| (j == block_y + all->map.blockh - 2
					&& i == block_x + all->map.blockw - 3))
				mvprintw(j, i, "*");
			else
				mvprintw(j, i, " ");
		}
		else
			mvprintw(j, i, " ");
		i++;
	}
}

static void			wkw_display_number(t_all *all, int x, int y, char *str)
{
	int				block_x;
	int				block_y;
	int				j;

	block_x = x * (all->map.width / all->map.size);
	block_y = y * (all->map.height / all->map.size);
	j = block_y + 1;
	while (j < block_y + all->map.blockh)
	{
		wkw_display_number_x(all, x, y, j);
		j++;
	}
	wkw_display_number_str(all, block_x, block_y, str);
}

static int			wkw_get_color(int n)
{
	int count;

	count = 0;
	while (n > 2)
	{
		n /= 2;
		count++;
	}
	return (count % COLOR_MAX + 1);
}

void				wkw_display_numbers(t_all *all)
{
	int				x;
	int				y;
	char			*str;

	y = 0;
	while (y < all->map.size)
	{
		x = 0;
		while (x < all->map.size)
		{
			if (all->map.tab[y][x] != 0)
			{
				attron(COLOR_PAIR(wkw_get_color(all->map.tab[y][x])));
				str = ft_itoa(all->map.tab[y][x]);
				wkw_display_number(all, x, y, str);
				free(str);
				attroff(COLOR_PAIR(1));
			}
			x++;
		}
		y++;
	}
}
