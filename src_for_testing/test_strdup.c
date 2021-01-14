/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:58:20 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:24:06 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void	ft_strdup_case(char *str)
{
	char	*my_ret;
	char	*org_ret;

	my_ret = ft_strdup(str);
	org_ret = strdup(str);
	if (!strcmp(my_ret, org_ret))
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%s|\tOriginal return: |%s|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
	free(my_ret);
	free(org_ret);
}

void		ft_strdup_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strdup test                  \n");
	printf("________________________________________________\n");
	ft_strdup_case("Hello world");
	ft_strdup_case("strdup		test");
	ft_strdup_case("");
	ft_strdup_case("Ç");
	ft_strdup_case("test\ttest");
	printf("\n\n");
}
