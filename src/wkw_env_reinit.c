/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_env_reinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:00:47 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:00:48 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wkw_reinit(t_all *all)
{
	int i;
	int j;

	all->score = 0;
	all->has_won = 0;
	all->has_already_won = 0;
	i = 0;
	while (i < all->map.size)
	{
		j = 0;
		while (j < all->map.size)
		{
			all->map.tab[i][j] = 0;
			j++;
		}
		i++;
	}
	wkw_gen_new_number(all);
	wkw_gen_new_number(all);
}
