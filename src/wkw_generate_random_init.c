/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_generate_random_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:59:41 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/19 15:02:51 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_rand_a_b_init(int a, int b)
{
	srand(time(NULL));
	return (rand() % (b - a) + a);
}

void		wkw_gen_new_number_init(t_all *all)
{
	int		i;
	int		nb;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	nb = ft_rand_a_b_init(1, 11);
	nb = (nb % 2 == 0 || nb % 3 == 0 ? 2 : 4);
	while (i == 0 || all->map.tab[pos.y][pos.x] != 0)
	{
		pos.y = ft_rand_a_b_init(0, all->map.size);
		pos.x = ft_rand_a_b_init(0, all->map.size);
		i++;
	}
	all->map.tab[pos.y][pos.x] = nb;
}
