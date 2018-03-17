/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:06:17 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/21 20:06:20 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_create_map(int size)
{
	int		j;
	char	**str;

	j = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		if ((str[j] = ft_strnew(size)) == NULL)
			return (NULL);
		str[j] = ft_memset(str[j], '.', size);
		j++;
	}
	str[j] = NULL;
	return (str);
}
