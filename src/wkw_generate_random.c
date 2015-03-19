/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_generate_random.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:01:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/19 15:03:23 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_rand_a_b(int a, int b)
{
	return (rand() % (b - a) + a);
}

void		wkw_gen_new_number(t_all *all)
{
	int		i;
	int		nb;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	nb = ft_rand_a_b(1, 11);
	nb = (nb % 2 == 0 || nb % 3 == 0 ? 2 : 4);
	while (i == 0 || all->map.tab[pos.y][pos.x] != 0)
	{
		pos.y = ft_rand_a_b(0, all->map.size);
		pos.x = ft_rand_a_b(0, all->map.size);
		i++;
	}
	all->map.tab[pos.y][pos.x] = nb;
}
