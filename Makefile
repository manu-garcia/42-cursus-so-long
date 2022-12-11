
NAME				=	so_long

SRC_DIR				=	src
INCLUDES_DIR		= 	includes minilibx/mlx.h

SOURCES				= 	$(SRC_DIR)/check_extension.c \
						$(SRC_DIR)/collision.c \
						$(SRC_DIR)/state.c \
						$(SRC_DIR)/events.c \
						$(SRC_DIR)/frame.c \
						$(SRC_DIR)/free.c \
						$(SRC_DIR)/load.c \
						$(SRC_DIR)/image.c \
						$(SRC_DIR)/hero.c \
						$(SRC_DIR)/monster.c \
						$(SRC_DIR)/map.c \
						$(SRC_DIR)/map_validation.c \
						$(SRC_DIR)/position.c \
						$(SRC_DIR)/error.c
MAIN_SOURCES		= 	$(SRC_DIR)/main.c $(SOURCES)
TEST_SOURCES		= 	$(SRC_DIR)/tests.c $(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)
TESTS_OBJS			= 	$(TEST_SOURCES:.c=.o)

LIB_FT_PRINTF		=	ft_printf
LIB_FT				=	libft
LIB_GNL				=	gnl

CFLAGS 				= 	-Wall -Wextra -Werror

OS := $(shell uname)
ifeq ($(OS), Darwin)
LIB_MINILIBX		=	minilibx
CFLAGS_MINILIBX		= 	-L . -lmlx -framework OpenGL -framework AppKit
LIB_MINILIBX_NAME	=	libmlx.a
else
LIB_MINILIBX		=	minilibx_mms_20200219
LIB_MINILIBX_NAME	=	libmlx.dylib
CFLAGS_MINILIBX		= 	-L . -lmlx -lXext -lX11
endif

CC 					= 	gcc

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I ${INCLUDES_DIR} -I ${LIB_GNL} -I ${LIB_MINILIBX} -o $@ $^

$(NAME): $(OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@make bonus -C $(LIB_GNL)
	@cp $(LIB_GNL)/libgnl.a .
	@make -C $(LIB_MINILIBX)
	@cp $(LIB_MINILIBX)/$(LIB_MINILIBX_NAME) .
	@$(CC) $(CFLAGS) $(CFLAGS_MINILIBX) -I ${INCLUDES_DIR} -I ${LIB_MINILIBX} $(OBJS) libgnl.a libft.a libftprintf.a $(LIB_MINILIBX_NAME) -o $(NAME)

bonus: $(NAME)

test: $(TESTS_OBJS)
	@make -C $(LIB_FT_PRINTF)
	@cp $(LIB_FT_PRINTF)/libftprintf.a .
	@make bonus -C $(LIB_FT)
	@cp $(LIB_FT)/libft.a .
	@make bonus -C $(LIB_GNL)
	@cp $(LIB_GNL)/libgnl.a .
	@make -C $(LIB_MINILIBX)
	@cp $(LIB_MINILIBX)/$(LIB_MINILIBX_NAME) .
	@$(CC) $(CFLAGS) $(CFLAGS_MINILIBX) -I ${INCLUDES_DIR} -I ${LIB_MINILIBX} $(TESTS_OBJS) libgnl.a libft.a libftprintf.a $(LIB_MINILIBX_NAME) -o so_long_tests
	@echo
	@echo Running tests ...
	@./so_long_tests

re: fclean all

clean:
	rm -f $(TESTS_OBJS) $(OBJS)
	rm ./libft.a
	rm ./libftprintf.a
	rm ./libgnl.a
	rm ./$(LIB_MINILIBX_NAME)
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
