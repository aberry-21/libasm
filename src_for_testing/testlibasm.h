/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibasm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:50:27 by aberry            #+#    #+#             */
/*   Updated: 2021/01/14 19:25:10 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIBASM_H
# define TESTLIBASM_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *str1, const char *str2);
ssize_t				ft_write(int fd, const void *buf, size_t count);
ssize_t				ft_read(int fd, void *buf, size_t count);
char				*ft_strdup(const char *str);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
t_list				*ft_create_elem(void *data);
int					ft_list_size_c(t_list *begin_list);
void				ft_list_push_front_c(t_list **begin_list, void *data);
void				ft_list_clear(t_list **begin_list);
void				ft_strlen_test(void);
void				ft_strcpy_test(void);
void				ft_strcmp_test(void);
void				ft_write_test(void);
void				ft_read_test(void);
void				ft_strdup_test(void);
void				ft_list_push_front_test(void);
void				ft_list_size_test(void);

#endif
