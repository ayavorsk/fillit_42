/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:42:25 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/22 15:42:26 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isempty_y(char **str, int x)
{
	int y;

	y = 0;
	while (y < 4)
	{
		if (str[y][x] == '#')
			return (0);
		y++;
	}
	return (1);
}

void		ft_mark_y(char **lines)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		if (ft_isempty_y(lines, x) == 1)
		{
			while (y < 4)
				lines[y++][x] = 'x';
		}
		x++;
	}
}
