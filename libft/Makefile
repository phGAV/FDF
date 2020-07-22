# TODO debug/release builds
NAME := libft.a
NAME_SHARED := libft.so

BUILD := build
INCLUDE := include

SRC := core/ft_apply.c core/ft_atoi.c core/ft_bzero.c core/ft_calloc.c core/ft_foreach.c core/ft_isalnum.c core/ft_isalpha.c core/ft_isascii.c core/ft_isdigit.c core/ft_islower.c core/ft_isprint.c core/ft_isspace.c core/ft_isupper.c core/ft_itoa.c core/ft_lstadd.c core/ft_lstdel.c core/ft_lstdelone.c core/ft_lstiter.c core/ft_lstmap.c core/ft_lstnew.c core/ft_malloc.c core/ft_map.c core/ft_memalloc.c core/ft_memccpy.c core/ft_memchr.c core/ft_memcmp.c core/ft_memcpy.c core/ft_memdel.c core/ft_memdup.c core/ft_memmove.c core/ft_memset.c core/ft_memswap.c core/ft_putchar.c core/ft_putchar_fd.c core/ft_putendl.c core/ft_putendl_fd.c core/ft_putnbr.c core/ft_putnbr_fd.c core/ft_putstr.c core/ft_putstr_fd.c core/ft_qsort.c core/ft_rand.c core/ft_realloc.c core/ft_strcat.c core/ft_strchr.c core/ft_strclr.c core/ft_strcmp.c core/ft_strcpy.c core/ft_strdel.c core/ft_strdup.c core/ft_strelems.c core/ft_strequ.c core/ft_striter.c core/ft_striteri.c core/ft_strjmp.c core/ft_strjoin.c core/ft_strlcat.c core/ft_strlen.c core/ft_strmap.c core/ft_strmapi.c core/ft_strncat.c core/ft_strncmp.c core/ft_strncpy.c core/ft_strnequ.c core/ft_strnew.c core/ft_strnstr.c core/ft_strrchr.c core/ft_strsplit.c core/ft_strspn.c core/ft_strstr.c core/ft_strsub.c core/ft_strtrim.c core/ft_tolower.c core/ft_toupper.c core/ft_umax.c core/ft_umin.c core/get_next_line.c vec/vec_append.c vec/vec_apply.c vec/vec_bsearch.c vec/vec_clear.c vec/vec_clone.c vec/vec_copy.c vec/vec_count.c vec/vec_create.c vec/vec_extend.c vec/vec_filter.c vec/vec_free.c vec/vec_get.c vec/vec_import.c vec/vec_index.c vec/vec_insert.c vec/vec_map.c vec/vec_pop.c vec/vec_remove.c vec/vec_resize.c vec/vec_reverse.c vec/vec_search.c vec/vec_set.c vec/vec_sort.c vec/vectorize.c 
OBJ := $(SRC:%.c=$(BUILD)/%.o)
DEP := $(OBJ:%.o=%.d)

# AR := llvm-ar
# RANLIB := llvm-ranlib
AR := ar
RANLIB := ranlib

CC := clang
WFLAGS := -Wall -Wextra
# WFLAGS += -Wpedantic
# WFLAGS += -Werror
OFLAGS := -O2 -march=native
OFLAGS += -ftree-vectorize
OFLAGS += -flto=thin
CFLAGS := $(WFLAGS) $(OFLAGS) -fPIC -MMD -I./$(INCLUDE)

vpath %.c src src/core src/vec 

.PHONY: all clean fclean re test love debug

$(NAME): $(OBJ)
	@echo "Linking '$@'..."
	@$(AR) rcs $@ $?
	@$(RANLIB) $@
	@echo "\x1b[32;1m[$(NAME)] Done\x1b[0m"

-include $(DEP)
$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@echo "[$(NAME)] Building object '$@'"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_SHARED): $(OBJ)
	@$(CC) $(CFLAGS) -shared -o $@ $^

all: $(NAME)

clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_SHARED)

re: fclean all

test: all
	@test/test.sh "$(CC)" "$(CFLAGS)" "-L./ $(NAME)"

love:
	@echo 'not war'
	@sh util/genmake.sh > Makefile

debug:
	@echo 'nope'
