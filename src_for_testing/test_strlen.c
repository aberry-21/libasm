/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:55:21 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:22:08 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void		ft_strlen_case(char *str)
{
	int		my_ret;
	int		org_ret;

	my_ret = ft_strlen(str);
	org_ret = strlen(str);
	if (my_ret == org_ret)
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%d|\tOriginal return: |%d|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void			ft_strlen_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strlen test                  \n");
	printf("________________________________________________\n");
	ft_strlen_case("Hello world");
	ft_strlen_case("					");
	ft_strlen_case("");
	ft_strlen_case("Ç");
	ft_strlen_case("\t");
	printf("\n\n");
}
