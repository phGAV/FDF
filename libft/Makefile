NAME = libft.a

OBJ_DIR = ./obj
SRC_DIR = ./

SRC = ft_apply.c ft_atoi.c ft_bzero.c ft_calloc.c ft_foreach.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	  ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	  ft_lstmap.c ft_lstnew.c ft_malloc.c ft_map.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c \
	  ft_memswap.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_realloc.c ft_strcat.c ft_strchr.c \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	  ft_strelems.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjmp.c ft_strjoin.c ft_strlcat.c \
	  ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	  ft_strsplit.c ft_strspn.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c ft_umax.c ft_umin.c ft_qsort.c get_next_line.c \
	  vec_append.c vec_apply.c vec_bsearch.c vec_clear.c vec_clone.c vec_copy.c \
	  vec_count.c vec_create.c vec_extend.c vec_filter.c \
	  vec_free.c vec_get.c vec_import.c vec_index.c vec_insert.c \
	  vec_map.c vec_pop.c vec_prepend.c vec_resize.c vec_reverse.c vec_search.c \
	  vec_set.c vec_sort.c vectorize.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(SRC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
