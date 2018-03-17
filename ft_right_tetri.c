/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:57:11 by okupin            #+#    #+#             */
/*   Updated: 2017/11/16 00:57:22 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_right_lines(char *str)
{
	size_t		width;
	size_t		i;
	size_t		w_line;

	i = 0;
	width = 0;
	w_line = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#')
			width++;
		if (width > 4)
			return (0);
		if (str[i] == '\n' && i == w_line)
		{
			w_line += 5;
			width = 0;
		}
		i++;
	}
	return (1);
}

static int	ft_right_chars(char *str)
{
	int		i;
	int		j;
	int		d;
	int		n;

	i = 0;
	j = 0;
	d = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			j++;
		if (str[i] == '.')
			d++;
		if (str[i] == '\n')
			n++;
		if (str[i] != '#' && str[i] != '\n' && str[i] != '.')
			return (0);
		i++;
	}
	if (j == 4 && d == 12 && n == 4)
		return (1);
	return (0);
}

static int	ft_right_connect(char *str)
{
	int		i;
	int		connect;

	connect = 0;
	i = 0;
	while (str[i] != '#')
		i++;
	while (i < 20)
	{
		if ((i + 1) < 20 && str[i + 1] == '#' && str[i] == '#')
			connect++;
		if ((i - 1) >= 0 && str[i - 1] == '#' && str[i] == '#')
			connect++;
		if ((i + 5) < 20 && str[i + 5] == '#' && str[i] == '#')
			connect++;
		if ((i - 5) >= 0 && str[i - 5] == '#' && str[i] == '#')
			connect++;
		i++;
	}
	if (connect == 6)
		return (connect);
	if (connect == 8)
		return (connect);
	return (0);
}

int			ft_right_tetri(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_right_lines(str) == 0)
		return (0);
	if (ft_right_chars(str) == 0)
		return (0);
	if (ft_right_connect(str) == 0)
		return (0);
	return (1);
}
