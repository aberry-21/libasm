/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:57:23 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:23:42 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

static void		*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)destination;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

static void		ft_read_case(int fd, void *buff, size_t count)
{
	ssize_t		my_ret;
	ssize_t		org_ret;

	write(1, "Input:", 7);
	my_ret = ft_read(fd, buff, count);
	if (errno || my_ret == (org_ret = strlen(buff)))
	{
		if (errno)
		{
			printf("\nValue of errno: %d\n", errno);
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

void			ft_read_test(void)
{
	char		buff[100];

	ft_memset(buff, 0, 100);
	errno = 0;
	printf("________________________________________________\n");
	printf("                 ft_read test                   \n");
	printf("________________________________________________\n");
	ft_read_case(0, buff, 30);
	ft_read_case(20, buff, 30);
	ft_read_case(0, buff, -30);
	ft_read_case(0, NULL, 30);
	printf("\n\n");
}
