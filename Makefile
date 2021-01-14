# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberry <aberry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 18:51:29 by aberry            #+#    #+#              #
#    Updated: 2021/01/14 18:13:04 by aberry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC_DIR = src/

SRC_FILES = ft_read.s\
			ft_strcmp.s\
			ft_strcpy.s\
			ft_strdup.s\
			ft_strlen.s\
			ft_write.s\

SRC_BONUS = ft_list_size_bonus.s\
			ft_create_elem_bonus.s\
			ft_list_push_front_bonus.s\

OBJ_DIR = obj/

OBJ_FILE =  $(SRC_FILES:.s=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

OBJ_FILE_BONUS =  $(SRC_BONUS:.s=.o)
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_FILE_BONUS))

all:	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.s
	@$ nasm -f macho64 -s $< -o $@

bonus:	all $(OBJ_DIR) $(OBJ_BONUS) 
	@ar rc $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)
	
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean  all

.PHONY: all clean fclean re