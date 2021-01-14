/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:56:28 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:24:28 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void		ft_write_case(int fd, const void *buf, size_t count)
{
	ssize_t		my_ret;
	ssize_t		org_ret;

	my_ret = ft_write(fd, buf, count);
	org_ret = write(fd, buf, count);
	if (my_ret == org_ret)
	{
		if (errno)
		{
			printf("Value of errno: %d\n", errno);
			printf("Error opening file: %s\n", strerror(errno));
		}
		printf("Test:\t\033[32m [OK] \t\033[0m\n\n");
	}
	else
	{
		printf("My return: |%lu|\tOriginal return: |%lu|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
}

void			ft_write_test(void)
{
	printf("________________________________________________\n");
	printf("                 ft_write test                  \n");
	printf("________________________________________________\n");
	ft_write_case(0, "test with fd = 0\n", 18);
	ft_write_case(1, "test with fd = 1\n", 18);
	ft_write_case(2, "test with fd = 2\n", 18);
	ft_write_case(20, "test_error\n", 18);
	ft_write_case(1, "test_error\n", -18);
	ft_write_case(2, NULL, 19);
	printf("\n\n");
}
