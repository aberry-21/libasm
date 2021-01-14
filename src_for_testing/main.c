/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:15:22 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:22:57 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibasm.h"

int		main(void)
{
	printf("________________________________________________\n");
	printf("\033[35m                TESTING LIBASM                  \n\033[0m");
	printf("\n\n");
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	ft_strdup_test();
	ft_list_push_front_test();
	ft_list_size_test();
	return (0);
}
