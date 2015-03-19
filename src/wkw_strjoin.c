/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:24:23 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/19 14:38:08 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static char		*ft_strcat(char *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;

	if (s1 && s2)
	{
		new = (char *)malloc(sizeof(char)
			* ((ft_strlen(s1) + ft_strlen(s2) + 1)));
		if (new)
		{
			new = ft_strcat(new, s1);
			new = ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}
