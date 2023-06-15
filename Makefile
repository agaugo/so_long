NAME        = so_long
MLX         = mlx/libmlx.a
PRINTF      = ft_printf/libftprintf.a
CC          = gcc
CC_FLAGS    = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS   = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR     = src
OBJ_DIR     = obj
GNL_DIR     = get_next_line

SRC         = free_and_utils.c map_checker.c so_long.c mlx_hooks.c player_movement.c
GNL_SRC     = get_next_line.c get_next_line_utils.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC)) $(addprefix $(GNL_DIR)/, $(GNL_SRC))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) $(addprefix $(OBJ_DIR)/get_next_line/, $(GNL_SRC:.c=.o))

# Colors
RED         = \033[0;31m
GREEN       = \033[0;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C mlx > /dev/null 2>&1
	@$(MAKE) -s -C ft_printf > /dev/null 2>&1
	@$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJS) $(MLX) $(PRINTF) -o $(NAME)
	@echo "\n$(GREEN)✔ so_long compiled ✔$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\n$(RED)[Compiling $<..........$(RESET)]"
	@$(CC) $(CC_FLAGS) -c $< -o $@ && printf "\n$(GREEN)[Compiled $<]$(RESET)"

$(OBJ_DIR)/get_next_line/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/get_next_line
	@printf "\n$(RED)[Compiling $<..........$(RESET)]"
	@$(CC) $(CC_FLAGS) -c $< -o $@ && printf "\n$(GREEN)[Compiled $<]$(RESET)"

clean:
	@$(MAKE) clean -C mlx > /dev/null 2>&1
	@$(MAKE) clean -C ft_printf > /dev/null 2>&1
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ft_printf > /dev/null 2>&1
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
