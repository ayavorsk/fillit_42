/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:54:20 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/14 23:54:20 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_replace(char *str, char search, char replace)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			str[i] = replace;
		i++;
	}
}

void			ft_replace_space(char **str, t_term *list)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_replace(str[i], list->symbol, '.');
		i++;
	}
}
