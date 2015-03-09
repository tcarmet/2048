/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_game_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:01:34 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/02 21:01:34 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	wkw_game_over(t_all *all)
{
	int status;

	if ((status = wkw_display_panel(all, GAME_OVER)) != STATUS_CONTINUE)
		return (status);
	wkw_reinit(all);
	wkw_display_ui(all);
	return (STATUS_CONTINUE);
}
