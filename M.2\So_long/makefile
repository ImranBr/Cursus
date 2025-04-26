CC = cc
CFLAGS = -Werror -Wextra -Wall -MMD -g3 -fPIC
INCLUDES = -Iincludes -I./lib/ft_printf/includes -I./lib/libft/includes -I./lib/get_next_line/includes -I$(MLX)
LIBPRINTF = lib/ft_printf/lib/libprintf.a
LIBFT = lib/libft/lib/libft.a
GET_NEXT_LINE = lib/get_next_line/lib/get_next_line.a
MLX = minilibx-linux
MLXFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm

SRC_DIR = src
OBJ_DIR = objs
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

DEPENDS = $(OBJS:.o=.d)

NAME = so_long
-include $(DEPEND)

all: $(MLX) $(NAME) 

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBPRINTF) $(LIBFT) $(GET_NEXT_LINE) -o $@ $(MLXFLAGS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

$(LIBFT):
	$(MAKE) -C lib/libft

$(GET_NEXT_LINE):
	$(MAKE) -C lib/get_next_line

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf clean
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/get_next_line clean

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf fclean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/get_next_line fclean

.PHONY: all
re: fclean all