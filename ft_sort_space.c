/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:52:46 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/14 23:52:46 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_put_space(char **space, t_term *ptr)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (space[i] != NULL)
	{
		j = 0;
		while (space[i][j] != '\0')
		{
			if (ptr->x[count] == j && ptr->y[count] == i)
			{
				space[i][j] = ptr->symbol;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count <= 3)
		return (NULL);
	return (space);
}

static int		ft_clear_space(t_term *ptr, char **str)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (ptr->x[count] == j && ptr->y[count] == i)
			{
				if (str[i][j] != '.')
					return (0);
				else
					count++;
			}
			j++;
		}
		i++;
	}
	if (count <= 3)
		return (0);
	return (1);
}

char			**ft_sort_space(char **str, t_term *l, int i, int j)
{
	char	**space;

	if (l->next != NULL)
	{
		while (str[i] != NULL)
		{
			j = 0;
			while (str[i][j] != '\0')
			{
				ft_new_cord(l, j, i);
				if ((ft_clear_space(l, str)))
				{
					space = ft_put_space(str, l);
					if ((space = ft_sort_space(space, l->next, 0, 0)) != NULL)
						return (space);
				}
				ft_replace_space(str, l);
				j++;
			}
			i++;
		}
		return (NULL);
	}
	return (str);
}
