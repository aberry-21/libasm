#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *str1, const char *str2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *str);

extern int errno ;

typedef struct		s_list
{
	void			*data; // rdi [rdi]
	struct s_list	*next; // [rdi + 8]
}					t_list;


void	ft_strlen_case(char *str)
{
	int		my_ret;
	int		org_ret;

	my_ret = ft_strlen(str);
	org_ret = strlen(str);
	if(my_ret == org_ret)
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%d|\tOriginal return: |%d|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void	ft_strlen_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strlen test                  \n");
	printf("________________________________________________\n");
	ft_strlen_case("Hello world");
	ft_strlen_case("					");
	ft_strlen_case("");
	ft_strlen_case("Ç");
	ft_strlen_case("\t");
}

void	ft_strcpy_case(char *str)
{
	char	str1[20];
	char	str2[20];

	if(!strcmp(ft_strcpy(str1, str), strcpy(str2, str)))
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%s|\tOriginal return: |%s|\n", str1, str2);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void	ft_strcpy_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strcpy test                  \n");
	printf("________________________________________________\n");
	ft_strcpy_case("Hello world");
	ft_strcpy_case("					");
	ft_strcpy_case("");
	ft_strcpy_case("Ç");
	ft_strcpy_case("test\ttest");
}


void	ft_strcmp_case(char *str)
{
	char	*str1;
	int		my_ret;
	int		org_ret;

	str1 = "test==";
	my_ret = ft_strcmp(str1, str);
	org_ret = strcmp(str1, str);
	if(my_ret == org_ret)
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%d|\tOriginal return: |%d|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void	ft_strcmp_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strcmp test                  \n");
	printf("________________________________________________\n");
	ft_strcmp_case("test==");
	ft_strcmp_case("test<");
	ft_strcmp_case("test>test");
	ft_strcmp_case("");
}


void	ft_write_case(int fd, const void *buf, size_t count)
{
	ssize_t		my_ret;
	ssize_t		org_ret;

	my_ret = ft_write(fd, buf, count);
	org_ret = write(fd, buf, count);
	if(my_ret == org_ret)
	{
		if (errno)
		{
			printf("Value of errno: %d\n", errno);
			printf("Error opening file: %s\n", strerror( errno ));
		}
		printf("Test:\t\033[32m [OK] \t\033[0m\n\n");
	}
	else
	{
		printf("My return: |%lu|\tOriginal return: |%lu|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
}

void	ft_write_test(void)
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
}






void	*ft_memset(void *destination, int c, size_t n)
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

void	ft_read_case(int fd,void *buff, size_t count)
{
	ssize_t		my_ret;
	ssize_t		org_ret;

	write(1, "Input:", 7);
	my_ret = ft_read(fd, buff, count);
	if(errno || my_ret == (org_ret = strlen(buff)))
	{
		if (errno)
		{
			printf("\nValue of errno: %d\n", errno);
			printf("Error opening file: %s\n", strerror( errno ));
		}
		printf("Test:\t\033[32m [OK] \t\033[0m\n\n");
	}
	else
	{
		printf("My return: |%lu|\tOriginal return: |%lu|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
}

void	ft_read_test(void)
{
	char		buff[100];

	ft_memset(buff, 0 , 100);
	errno = 0;
	printf("________________________________________________\n");
	printf("                 ft_read test                   \n");
	printf("________________________________________________\n");
	ft_read_case(0,  buff, 30);
	ft_read_case(20, buff,  30);
	ft_read_case(0, buff,  -30);
	ft_read_case(0, NULL,  30);
}



void	ft_strdup_case(char *str)
{
	char	*my_ret;
	char	*org_ret;

	my_ret = ft_strdup(str);
	org_ret = strdup(str);
	if(!strcmp(my_ret, org_ret))
		printf("\033[32m [OK] \t\033[0m");
	else
	{
		printf("My return: |%s|\tOriginal return: |%s|\n", my_ret, org_ret);
		printf("\033[31m [FAIL] \t\033[0m");
	}
	printf("Test string: |%s|\n", str);
}

void	ft_strdup_test(void)
{
	printf("________________________________________________\n");
	printf("                ft_strdup test                  \n");
	printf("________________________________________________\n");
	ft_strdup_case("Hello world");
	ft_strdup_case("strdup		test");
	ft_strdup_case("");
	ft_strdup_case("Ç");
	ft_strdup_case("test\ttest");
}

int		main(void)
{
	printf("________________________________________________\n");
	printf("\033[35m                TESTING LIBASM                  \n\033[0m");
	printf("\n\n");
	ft_strlen_test();
	printf("\n\n");
	ft_strcpy_test();
	printf("\n\n");
	ft_strcmp_test();
	printf("\n\n");
	ft_write_test();
	printf("\n\n");
	ft_read_test();
	printf("\n\n");
	ft_strdup_test();
	return (0);
}
