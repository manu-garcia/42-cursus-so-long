# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 18:26:06 by manu              #+#    #+#              #
#    Updated: 2022/05/09 00:01:15 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRC_DIR			=	src
MANDATORY_SRC 	:= 	$(shell find ./$(SRC_DIR) -name '*.c')
MANDATORY_OBJ 	= 	$(MANDATORY_SRC:.c=.o)
CFLAGS 			= 	-Wall -Wextra -Werror
CC 				= 	gcc

all: $(NAME)
		
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(FLAGS) -o $@ $^

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)

re: fclean $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

testme:
	rm -f .a.out
	rm -f $(MANDATORY_OBJ)
	gcc -g $(MANDATORY_SRC) test.c

.PHONY: all clean fclean re