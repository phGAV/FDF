NAME := fdf

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)

MLX_DIR := minilibx_macos

OBJ_DIR := obj
INCLUDE := include

SRC := main.c draw.c keyboard.c errors.c read_map.c projection.c
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

CC := clang
MLX_FLAGS := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# -Werror
CFLAGS := -Wall -Wextra -std=c99 -march=native -O2 -ftree-vectorize -fPIC -MMD -I. -I./$(INCLUDE) -I./$(LIBFT_INCLUDE) -I./$(MLX_DIR)
LDFLAGS := -fuse-linker-plugin -Wl,--strip-all,--sort-common,--as-needed,-z,relro

vpath %.c src

# @$(MAKE) -C $(LIBFT_DIR) all
# @$(MAKE) -C $(MLX_DIR) all
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_LIB) $(OBJ) -o $(NAME)

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

# @$(MAKE) -C $(MLX_DIR) clean
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

# @$(MAKE) -C $(MLX_DIR) fclean
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

love:
	@echo 'not war'

.PHONY: all clean fclean re test
