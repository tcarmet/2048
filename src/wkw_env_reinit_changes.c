/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_env_reinit_changes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:01:02 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:01:03 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wkw_reinit_changes(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < all->map.size)
	{
		j = 0;
		while (j < all->map.size)
		{
			all->map.tab_changes[i][j] = 0;
			j++;
		}
		i++;
	}
}
