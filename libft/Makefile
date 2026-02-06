NAME = libft.a

# Directories
IS_DIR = is
MEM_DIR = mem
STR_DIR = str
LST_DIR = lst
PUT_DIR = put
CONV_DIR = conv
PRINTF_DIR = printf

# Source files by category
IS_SRC = $(IS_DIR)/ft_isalpha.c $(IS_DIR)/ft_isdigit.c $(IS_DIR)/ft_isalnum.c \
		$(IS_DIR)/ft_isascii.c $(IS_DIR)/ft_isprint.c

MEM_SRC = $(MEM_DIR)/ft_memset.c $(MEM_DIR)/ft_bzero.c $(MEM_DIR)/ft_memcpy.c \
		$(MEM_DIR)/ft_memmove.c $(MEM_DIR)/ft_memchr.c $(MEM_DIR)/ft_memcmp.c \
		$(MEM_DIR)/ft_calloc.c

STR_SRC = $(STR_DIR)/ft_strlen.c $(STR_DIR)/ft_strlcpy.c $(STR_DIR)/ft_strlcat.c \
		$(STR_DIR)/ft_strchr.c $(STR_DIR)/ft_strrchr.c $(STR_DIR)/ft_strncmp.c \
		$(STR_DIR)/ft_strnstr.c $(STR_DIR)/ft_strdup.c $(STR_DIR)/ft_substr.c \
		$(STR_DIR)/ft_strjoin.c $(STR_DIR)/ft_strtrim.c $(STR_DIR)/ft_split.c \
		$(STR_DIR)/ft_strmapi.c $(STR_DIR)/ft_striteri.c

LST_SRC = $(LST_DIR)/ft_lstnew_bonus.c $(LST_DIR)/ft_lstadd_front_bonus.c \
		$(LST_DIR)/ft_lstadd_back_bonus.c $(LST_DIR)/ft_lstdelone_bonus.c \
		$(LST_DIR)/ft_lstclear_bonus.c $(LST_DIR)/ft_lstiter_bonus.c \
		$(LST_DIR)/ft_lstmap_bonus.c $(LST_DIR)/ft_lstsize_bonus.c \
		$(LST_DIR)/ft_lstlast_bonus.c

PUT_SRC = $(PUT_DIR)/ft_putchar_fd.c $(PUT_DIR)/ft_putstr_fd.c \
		$(PUT_DIR)/ft_putendl_fd.c $(PUT_DIR)/ft_putnbr_fd.c

CONV_SRC = $(CONV_DIR)/ft_atoi.c $(CONV_DIR)/ft_itoa.c $(CONV_DIR)/ft_tolower.c \
		$(CONV_DIR)/ft_toupper.c

PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printf_utils.c

# All source files
SRC = $(IS_SRC) $(MEM_SRC) $(STR_SRC) $(PUT_SRC) $(CONV_SRC) $(PRINTF_SRC)
BONUS_SRC = $(LST_SRC)

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

%.o: %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

bonus:	${OBJS} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
