NAME := fdf

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)/include

MLX_DIR := minilibx_macos

BUILD := build
INCLUDE := include

SRC := main.c draw.c color.c keyboard.c errors.c read_map.c \
		draw_map.c projection.c mouse.c keyboard_functions.c \
		keyboard_functions_fx.c camera.c
OBJ := $(SRC:%.c=$(BUILD)/%.o)
DEP := $(OBJ:%.o=%.d)

CC := clang
# AR := llvm-ar
# RANLIB := llvm-ranlib
AR := ar
RANLIB := ranlib

CC := clang
WFLAGS := -Wall -Wextra
# WFLAGS += -Wpedantic
# WFLAGS += -Werror
OFLAGS := -O2 -march=native
# OFLAGS := -g
OFLAGS += -ftree-vectorize
# OFLAGS += -flto=thin
CFLAGS := $(WFLAGS) $(OFLAGS) -fPIC -MMD -I./$(INCLUDE) -I./$(LIBFT_INCLUDE) -I./$(MLX_DIR)
MLX_FLAGS := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

vpath %.c src

.PHONY: all clean fclean re test love debug

$(NAME): $(OBJ)
	@echo "Linking '$@'..."
	@$(MAKE) -C $(MLX_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_LIB) $(OBJ) -o $(NAME)
	@echo "\x1b[32;1m[$(NAME)] Done\x1b[0m"

-include $(DEP)
$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@echo "[$(NAME)] Building object '$@'"
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(BUILD)

fclean: clean
	# @$(MAKE) -C $(MLX_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

test: all
	@./fdf test_maps/42.fdf

love:
	@echo 'not war'
