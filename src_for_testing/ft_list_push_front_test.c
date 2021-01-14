/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:14:46 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:22:28 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void		ft_list_create(t_list **my_list, t_list **org_list, char *str)
{
	if (!str)
	{
		ft_list_push_front(my_list, "First data");
		ft_list_push_front(org_list, "first data");
	}
	else
	{
		*my_list = ft_create_elem(str);
		*org_list = ft_create_elem(str);
	}
	ft_list_push_front(my_list, "data example");
	ft_list_push_front(org_list, "data example");
}

static void		ft_list_push_front_case(char *str)
{
	t_list		*my_list;
	t_list		*org_list;

	ft_list_create(&my_list, &org_list, str);
	if (ft_list_size_c(my_list) == ft_list_size_c(org_list))
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("\033[31m [FAIL] \t\033[0m");
		printf("My return: |%s|\tOriginal return: |%s|\n", my_list->data,
		org_list->data);
	}
	printf("Test string: |%s|\n", str);
	ft_list_clear(&my_list);
	ft_list_clear(&org_list);
}

void			ft_list_push_front_test(void)
{
	printf("________________________________________________\n");
	printf("              ft_list_push_front test           \n");
	printf("________________________________________________\n");
	ft_list_push_front_case("First elem");
	ft_list_push_front_case(NULL);
	printf("\n\n");
}
