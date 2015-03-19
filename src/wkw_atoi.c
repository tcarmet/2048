/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:23:32 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/19 14:37:39 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		ft_isspace(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static int		ft_isnumber(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int				ft_atoi(char const *str)
{
	int		pos;
	int		neg;
	int		res;

	pos = 0;
	neg = 0;
	res = 0;
	while (ft_isspace(str[pos]))
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			neg = 1;
		pos++;
	}
	while (str[pos] && ft_isnumber(str[pos]))
	{
		res = res * 10;
		res += (str[pos] - 48);
		pos++;
	}
	if (neg)
		res = res * -1;
	return (res);
}
