/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_env_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:00:27 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:00:27 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	wkw_init_map_changes(t_all *all, int size)
{
	int i;

	i = 0;
	all->map.tab_changes = (int **)ft_memalloc(sizeof(int *) * (size + 1));
	if (!all->map.tab_changes)
		return (wkw_error(SYSCALL));
	while (i < size)
	{
		all->map.tab_changes[i] = (int *)ft_memalloc(sizeof(int) * size);
		if (!all->map.tab_changes[i])
			return (wkw_error(SYSCALL));
		i++;
	}
	all->map.tab_changes[i] = NULL;
	return (STATUS_CONTINUE);
}

int			wkw_init_map(t_all *all, int size)
{
	int i;

	i = 0;
	all->map.size = size;
	all->map.tab = (int **)ft_memalloc(sizeof(int *) * (size + 1));
	if (!all->map.tab)
		return (wkw_error(SYSCALL));
	while (i < size)
	{
		all->map.tab[i] = (int *)ft_memalloc(sizeof(int) * size);
		if (!all->map.tab[i])
			return (wkw_error(SYSCALL));
		i++;
	}
	all->map.tab[i] = NULL;
	wkw_gen_new_number(all);
	wkw_gen_new_number(all);
	return (wkw_init_map_changes(all, size));
}
