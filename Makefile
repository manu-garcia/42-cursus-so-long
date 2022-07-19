
NAME				=	so_long

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				= 	$(SRC_DIR)/check_extension.c \
						$(SRC_DIR)/state.c \
						$(SRC_DIR)/error.c
MAIN_SOURCES		= 	$(SRC_DIR)/main.c $(SOURCES)
TEST_SOURCES		= 	$(SRC_DIR)/tests.c $(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)
TESTS_OBJS			= 	$(TEST_SOURCES:.c=.o)

LIB_FT_PRINTF		=	ft_printf
LIB_FT				=	libft
LIB_GNL				=	gnl
LIB_MINILIBX		=	minilibx
CFLAGS 				= 	-Wall -Wextra -Werror
CFLAGS_MINILIBX		= 	-L . -lmlx -framework OpenGL -framework AppKit
CC 					= 	gcc

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I ${INCLUDES_DIR} -o $@ $^

$(NAME): $(OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@make bonus -C $(LIB_GNL)
	@cp $(LIB_GNL)/libgnl.a .
	@make -C $(LIB_MINILIBX)
	@cp $(LIB_MINILIBX)/libmlx.a .
	@$(CC) $(CFLAGS) $(CFLAGS_MINILIBX) -I ${INCLUDES_DIR} -I ${LIB_MINILIBX} $(OBJS) libgnl.a libft.a libftprintf.a libmlx.a -o $(NAME)

test: $(TESTS_OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@make bonus -C $(LIB_GNL)
	@cp $(LIB_GNL)/libgnl.a .
	@make -C $(LIB_MINILIBX)
	@cp $(LIB_MINILIBX)/libmlx.a .
	@$(CC) $(CFLAGS) $(CFLAGS_MINILIBX) -I ${INCLUDES_DIR} -I ${LIB_MINILIBX} $(TESTS_OBJS) libgnl.a libft.a libftprintf.a libmlx.a -o so_long_tests
	@echo
	@echo Running tests ...
	@./so_long_tests

re: fclean all

clean:
	rm -f $(TESTS_OBJS) $(OBJS)
	rm ./libft.a
	rm ./libftprintf.a
	rm ./libmlx.a .
	@make fclean -C $(LIB_GNL)
	@make fclean -C $(LIB_FT)
	@make fclean -C $(LIB_FT_PRINTF)
	@make clean -C $(LIB_MINILIBX)

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

valgrind:
	valgrind --leak-check=full --track-origins=yes ./so_long

.PHONY: all clean fclean re test valgrind
