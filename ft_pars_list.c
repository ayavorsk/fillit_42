/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:09:21 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/06 17:09:22 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_term		*ft_pars_list(char *str, int i)
{
	t_term		*pars;
	t_term		*begin;
	char		*sqr;
	int			j;
	char		a;

	a = 'A';
	j = 0;
	if ((pars = (t_term*)malloc(sizeof(t_term))) == NULL)
		return (NULL);
	begin = pars;
	while (i-- != 0)
	{
		sqr = ft_strsub(str, j, SIZE);
		if ((ft_right_tetri(sqr)) == 0)
			ft_put_error('E');
		pars = ft_set_cord(pars, (ft_del_cut(ft_strsplit(sqr, '\n'))));
		pars->symbol = a++;
		if ((pars->next = (t_term*)malloc(sizeof(t_term))) == NULL)
			return (NULL);
		pars = pars->next;
		j += 21;
	}
	pars->next = NULL;
	return (begin);
}
