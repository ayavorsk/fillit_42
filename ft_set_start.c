/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:56:26 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/15 21:56:26 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**ft_sort_result(t_term *list, int size)
{
	char	**space;

	space = ft_create_map(size);
	space = ft_sort_space(space, list, 0, 0);
	if (space == NULL)
	{
		ft_arr_del(space);
		free(space);
		return (ft_sort_result(list, size + 1));
	}
	return (space);
}

static int			ft_check_coob(t_term *list)
{
	int i;

	i = 0;
	if (list->x[i] == 0 && list->y[i] == 0)
		i++;
	if (list->x[i] == 1 && list->y[i] == 0)
		i++;
	if (list->x[i] == 0 && list->y[i] == 1)
		i++;
	if (list->x[i] == 1 && list->y[i] == 1)
		i++;
	if (i == 4)
		return (1);
	return (0);
}

static int			ft_mach_coob(t_term *list)
{
	int i;

	i = 0;
	while (list->next != NULL)
	{
		if ((ft_check_coob(list)) == 1)
			i++;
		list = list->next;
	}
	return (i);
}

void				ft_set_start(t_term *list, int size)
{
	int		i;
	char	**space;

	i = 2;
	while (i * i < size * 4)
		i++;
	if ((ft_mach_coob(list)) > 9)
		space = ft_sort_result(list, i + 1);
	else
		space = ft_sort_result(list, i);
	ft_arrstr(space);
	ft_arr_del(space);
	free(space);
}
