
NAME = libft.a

MANDATORY_SRC := $(shell find . \( -name '*.c' -a -not -name '*bonus.c' \))
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

ALL_SRC := $(shell find . \( -name '*.c' \))
ALL_OBJ = $(ALL_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

%.o:	%.c
		$(CC) -c $(CFLAGS) $^

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)

re: fclean $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

bonus: $(ALL_OBJ)
	ar rcs $(NAME) $(ALL_OBJ)

testme:
	rm -f .a.out
	rm -f $(ALL_OBJ)
	rm -f $(NAME)
	gcc -g $(ALL_SRC)

.PHONY: all clean fclean re bonus

