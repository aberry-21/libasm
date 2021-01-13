#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *str1, const char *str2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
char		*ft_strdup(const char *str);

extern int errno ;

typedef struct		s_list
{
	void			*data; // rdi [rdi]
	struct s_list	*next; // [rdi + 8]
}					t_list;


void	ft_strlen_case(char *str)
{
	if(ft_strlen(str) == strlen(str))
		printf("\033[32m [OK] \t\033[0m");
	else
		printf("\033[31m [FAIL] \t\033[0m");
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


int		main(void)
{
	printf("________________________________________________\n");
	printf("\033[35m                TESTING LIBASM                  \n\033[0m");
	printf("\n\n");
	ft_strlen_test();
	// printf("%lu\n", ft_strlen("NULL"));
	// printf("%lu\n", strlen("NULL"));
	// char str1[7];
	// printf("%s\n", strcpy(str1, "qwerty"));
	// printf("%s\n", ft_strcpy(str1, "qwerty"));
	// char str1[9] = "qwerty";
	// printf("%d\n", strcmp(str1, "qwerty"));
	// printf("%d\n", ft_strcmp(str1, "qwerty"));
	//printf("%s\n", ft_strcpy(str1, "qwerty"));
	//ft_write(-1, "qwe", 3);
	// ft_write(1, "qwe", 3);
	// printf("Value of errno: %d\n", errno);
	// printf("Error opening file: %s\n", strerror( errno ));
	// printf("%s\n", ft_strdup("qwerty"));
	return (0);
}
