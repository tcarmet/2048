/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_memalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 18:35:30 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/04 18:35:37 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!size)
		return (NULL);
	str = (void*)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void*)str, size);
	return ((void*)str);
}
