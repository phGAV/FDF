NAME := fdf

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)

OBJ_DIR := obj
INCLUDE := include

SRC := main.c
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

CC := clang
# -Werror
CFLAGS := -Wall -Wextra -std=c99 -march=native -O2 -ftree-vectorize -fPIC -MMD -I. -I./$(INCLUDE) -I./$(LIBFT_INCLUDE)
LDFLAGS := -fuse-linker-plugin -Wl,--strip-all,--sort-common,--as-needed,-z,relro

vpath %.c src

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) all
	@cp $(LIBFT_LIB) $@
	@ar rcs $@ $?
	@ranlib $@

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

test: all
	@echo 'Not today darling, not today.'
	$(CC) test/main.c -L./ $(NAME) -I./$(INCLUDE) -I./$(LIBFT_INCLUDE) -o test/test && test/test

love:
	@echo 'not war'

.PHONY: all clean fclean re test
