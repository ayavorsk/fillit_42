/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:30:42 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/21 20:30:42 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_xmin(t_term *list)
{
	int min;
	int i;

	i = 1;
	min = list->x[0];
	while (i != 4)
	{
		if (list->x[i] < min)
			min = list->x[i];
		i++;
	}
	return (min);
}

static int		ft_ymin(t_term *list)
{
	int min;
	int i;

	i = 1;
	min = list->y[0];
	while (i != 4)
	{
		if (list->y[i] < min)
			min = list->y[i];
		i++;
	}
	return (min);
}

void			ft_new_cord(t_term *list, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = ft_xmin(list);
	ymin = ft_ymin(list);
	i = 0;
	while (i != 4)
	{
		list->x[i] = list->x[i] - xmin + x;
		list->y[i] = list->y[i] - ymin + y;
		i++;
	}
}
