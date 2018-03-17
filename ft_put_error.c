/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:46:32 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/21 19:46:35 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_error(char ch)
{
	if (ch == 'E')
	{
		write(1, "error\n", 6);
		exit(0);
	}
	else if (ch == 'U')
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
}
