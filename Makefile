# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/16 15:46:45 by yitoh         #+#    #+#                  #
#    Updated: 2024/02/16 15:51:28 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = cub3D
SRC = src/main.c
	  src/init.c
# OBJ = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = ./obj/
MLX_DIR = ./MLX42/build
MLX = $(MLX_DIR)/libmlx42.a
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

OBJ		=$(SRC:src/%.c=obj/%.o)

all:	$(NAME)

clean:
	@$(RM) -r obj
	@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
	@$(RM) $(NAME)
	@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

$(OBJ):		$(SRC) philosophers.h Makefile
	@mkdir -p $(dir $@)
	@printf "\e[1;34mBuilding $@\n\e[0;00m"
	@$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	@cp $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

$(NAME):	$(OBJ) $(MLX) $(LIBFT)
	@printf "\e[1;36mCompiling $@\n\e[0;00m"
	@$(CC) $(CFLAG) $^ -Iinclude -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $@
	@printf "\e[1;32mDone\e[0;00m\n"

.PHONY:		all clean fclean re libft



