/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:55:49 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:23:51 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void	ft_strcmp_case(char *str)
{
	char	*str1;
	int		my_ret;
	int		org_ret;

	str1 = "test==";
	my_ret = ft_strcmp(str1, str);
	org_ret = strcmp(str1, str);
	if (my_ret == org_ret)
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%d|\tOriginal return: |%d|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void		ft_strcmp_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strcmp test                  \n");
	printf("________________________________________________\n");
	ft_strcmp_case("test==");
	ft_strcmp_case("test<");
	ft_strcmp_case("test>test");
	ft_strcmp_case("");
	printf("\n\n");
}
