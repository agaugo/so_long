#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2023/03/09 13:07:39 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME		= so_long
MLX			= mlx/libmlx.a
CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR 	= src
OBJ_DIR 	= obj
GNL_DIR 	= get_next_line

SRC			= tools.c so_long.c hooks.c 
GNL_SRC 	= get_next_line.c get_next_line_utils.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC)) $(addprefix $(GNL_DIR)/, $(GNL_SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) $(addprefix $(OBJ_DIR)/get_next_line/, $(GNL_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C mlx > /dev/null 2>&1
	$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJS) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/get_next_line
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C mlx

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
