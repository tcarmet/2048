/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:20:30 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/19 14:36:39 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <string.h>

static void			ft_itoa_getlength(size_t *len, int *n)
{
	int				n2;

	*len = 0;
	n2 = *n;
	while (n2 != 0)
	{
		(*len)++;
		n2 = n2 / 10;
	}
}

char				*ft_itoa(int n)
{
	char				*str;
	size_t				len;
	unsigned int		n2;

	ft_itoa_getlength(&len, &n);
	n2 = (n < 0 ? -n : n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - (n < 0 ? 0 : 1)] = (n2 % 10) + 48;
		n2 = n2 / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
