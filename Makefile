# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberry <aberry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 18:51:29 by aberry            #+#    #+#              #
#    Updated: 2021/01/13 20:30:53 by aberry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC_DIR = src/

SRC_FILES = ft_read.s\
			ft_strcmp.s\
			ft_strcpy.s\
			ft_strdup.s\
			ft_strlen.s\
			ft_write.s

OBJ_DIR = obj/
OBJ_FILE =  $(SRC_FILES:.s=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

all:	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m \tcompiled \t libasm \t finish \033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\033[36m \tmkdir \t\t objects \t finish \033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@$ nasm -f macho64 -s $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[35m \tclean \t\t\t\t finish \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[35m \tfclean \t\t\t\t finish \033[0m"

re: fclean  all

.PHONY: all clean fclean re

# gcc -o exec main.c libasm.a && ./exec