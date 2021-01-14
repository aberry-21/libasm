/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:22:32 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 21:36:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void		ft_list_size_case(int num)
{
	t_list		*list;
	int			my_ret;
	int			org_ret;
	int			tmp_num;

	list = NULL;
	tmp_num = num + 1;
	while (--tmp_num)
		ft_list_push_front(&list, "data");
	org_ret = ft_list_size_c(list);
	my_ret = ft_list_size(list);
	if (org_ret == my_ret)
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("\033[31m [FAIL] \t\033[0m");
		printf("My return: |%d|\tOriginal return: |%d|\n", org_ret, my_ret);
	}
	printf("Count elems: |%d|\n", num);
	ft_list_clear(&list);
}

void			ft_list_size_test(void)
{
	printf("________________________________________________\n");
	printf("               ft_list_size test                \n");
	printf("________________________________________________\n");
	ft_list_size_case(5);
	ft_list_size_case(0);
}
