/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:01:09 by okupin            #+#    #+#             */
/*   Updated: 2017/11/16 01:01:17 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_term		*ft_set_cord(t_term *begin, char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	begin->content = str;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				begin->x[count] = j;
				begin->y[count] = i;
				count++;
			}
			j++;
		}
		i++;
	}
	return (begin);
}
