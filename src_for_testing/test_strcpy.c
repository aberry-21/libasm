/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:55:15 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:23:58 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void	ft_strcpy_case(char *str)
{
	char	str1[20];
	char	str2[20];

	if (!strcmp(ft_strcpy(str1, str), strcpy(str2, str)))
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%s|\tOriginal return: |%s|\n", str1, str2);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void		ft_strcpy_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strcpy test                  \n");
	printf("________________________________________________\n");
	ft_strcpy_case("Hello world");
	ft_strcpy_case("					");
	ft_strcpy_case("");
	ft_strcpy_case("Ç");
	ft_strcpy_case("test\ttest");
	printf("\n\n");
}
