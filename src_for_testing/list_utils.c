/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:12:45 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:22:53 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

int			ft_list_size_c(t_list *begin_list)
{
	t_list	*list;
	int		counter;

	counter = 0;
	list = begin_list;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

void		ft_list_push_front_c(t_list **begin_list, void *data)
{
	t_list	*list;

	list = ft_create_elem(data);
	if (*begin_list)
		list->next = *begin_list;
	*begin_list = list;
}

void		ft_list_clear(t_list **begin_list)
{
	t_list *list;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		free(list);
	}
	*begin_list = NULL;
}
