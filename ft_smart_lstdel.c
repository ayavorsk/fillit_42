/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_lstdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:37:38 by okupin            #+#    #+#             */
/*   Updated: 2017/11/16 16:37:39 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_smart_lstdel(t_term **alst)
{
	t_term *list;
	t_term *save;

	list = *alst;
	if (alst != NULL)
	{
		while (list->next != NULL)
		{
			save = list->next;
			ft_arr_del(list->content);
			free(list->content);
			free(list);
			list = save;
		}
		if (list->next != NULL && list->content != NULL)
		{
			ft_arr_del(list->content);
			free(list->content);
		}
		if (list->next != NULL)
			free(list);
	}
}
