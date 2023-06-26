# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 15:44:47 by hflohil-          #+#    #+#              #
#    Updated: 2023/06/23 16:04:22 by hflohil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = mlx/libmlx.a
PRINTF = ft_printf/libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src
OBJ_DIR = obj
GNL_DIR = get_next_line

SRC = misc_utils.c render_map.c map_parser.c memory_utils.c map_checker.c so_long.c mlx_hooks.c player_movement.c
GNL_SRC = get_next_line.c get_next_line_utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC)) $(addprefix $(GNL_DIR)/, $(GNL_SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) $(addprefix $(OBJ_DIR)/get_next_line/, $(GNL_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C mlx > /dev/null 2>&1
	@$(MAKE) -s -C ft_printf
	@$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJS) $(MLX) $(PRINTF) -o $(NAME)
	@echo "so_long compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/get_next_line
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C mlx > /dev/null
	@$(MAKE) clean -C ft_printf > /dev/null
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ft_printf > /dev/null 2>&1
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
