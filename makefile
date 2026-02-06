NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fractol.c parser.c parser_utils.c init.c utils1.c \
       render.c mandelbrot.c julia.c color.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx_linux
LIBFT_DIR = libft
PRINTF_DIR = printf
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lpthread
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I.

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f *.o
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
