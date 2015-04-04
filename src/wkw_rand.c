/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:02:36 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/04 19:36:09 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			ft_rand_a_b(int a, int b)
{
	int		fd;
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &i, sizeof(i));
	close(fd);
	if (i < 0 && a >= 0)
		i *= -1;
	i = i % (b - a) + a;
	return (i);
}
