/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:42:25 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/22 15:42:26 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isempty_x(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

void		ft_mark_x(char **lines)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		if (ft_isempty_x(lines[y]) == 1)
		{
			while (x < 4)
				lines[y][x++] = 'x';
		}
		y++;
	}
}
