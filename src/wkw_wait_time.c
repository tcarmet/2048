/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_wait_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:03:42 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:03:42 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wkw_wait_time(void)
{
	time_t now;
	time_t old;

	old = time(NULL);
	while (1)
	{
		now = time(NULL);
		if (now - old >= 1)
			break ;
	}
}
