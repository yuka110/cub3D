# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/16 15:46:45 by yitoh         #+#    #+#                  #
#    Updated: 2024/02/29 18:25:53 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# MLX_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit // for linux
MLX_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
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
HEADERS = ./Libft ./include ./MLX42/include/MLX42 

all: ${NAME}

${OBJ_DIR}%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

${LIB_MLX}: $(HEADERS)
	@git submodule update --init
	@cmake ${MLX_DIRECTORY} -B ${MLX_DIRECTORY}/build
	@$(MAKE) -C ${MLX_DIRECTORY}/build -j4

${LIBFT}: $(HEADERS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

${NAME}: ${OBJ} ${LIB_MLX} ${LIBFT}
	@echo "${BLUE}Compiling ${NAME}${END}"
	@$(CC) $(CFLAGS) $(OBJ) -o ${NAME} ${LIB_MLX} $(MLX_FLAGS) ${LIBFT}
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
