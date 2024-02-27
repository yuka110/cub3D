# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/16 15:46:45 by yitoh         #+#    #+#                  #
#    Updated: 2024/02/27 13:49:28 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = cub3D
SRC = src/main.c\
	  src/init.c\
	  src/checkmap.c\
	  src/parsemap.c\
	  src/cleanup.c\
	  src/testprint.c\
	  src/init_screen.c 
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIB_MLX = ./MLX42/build/libmlx42.a
MLX_DIRECTORY = ./MLX42
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = ./libft ./include ./MLX42/include/MLX42 

${OBJ}:	${SRC} $(HEADERS)
	@mkdir -p $(dir $@)
	@printf "\e[1;34mBuilding $@\n\e[0;00m"
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: ${LIB_MLX} ${LIBFT} ${NAME}

${LIB_MLX}:
	@git submodule update --init
	@cmake ${MLX_DIRECTORY} -B ${MLX_DIRECTORY}/build
	@make -C ${MLX_DIRECTORY}/build -j4

${LIBFT}: $(HEADERS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)


${NAME}: ${OBJ} $(HEADERS)
	@make -s -C $(LIBFT_DIR)
	@echo "${BLUE}Compiling ${NAME}${END}"
	@$(CC) $(CFLAGS) $(OBJ) ${LIB_MLX} ${LIBFT} $(MLX_FLAGS) -o $(NAME)
	@echo "${GREEN}Done!${END}"


clean:
	@$(RM) -r obj
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf ${MLX_DIRECTORY}/build
	@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all
.PHONY:		all clean fclean re libft



