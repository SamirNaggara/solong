NAME			= 	solong
SOURCE_FOLDER	=	source
MATH_LIB		= 	-lm
LIB_PATH		=	libft-plus
LIBFT 			= 	$(LIB_PATH)/libft.a
PRINTF			=	$(LIB_PATH)/printf.a 
GNL				=	$(LIB_PATH)/gnl.a 
CC				=	gcc $(FLAGS)
RM				=	rm -f	
MLX				= 	mlx_linux/libmlx.a
FLAGS			= 	-Wall -Wextra -Werror -g	
GREEN			= 	\033[0;32m
BIG				= 	\033[0;1m
RESET			= 	\033[0m



SOURCES	=	./main.c \
			./$(SOURCE_FOLDER)/parsing/create_map_utils.c \
			./$(SOURCE_FOLDER)/parsing/create_map.c \
			./$(SOURCE_FOLDER)/parsing/destroy_map.c \
			./$(SOURCE_FOLDER)/parsing/display_map.c \
			./$(SOURCE_FOLDER)/parsing/init.c \
			./$(SOURCE_FOLDER)/parsing/valid_way.c \
			./$(SOURCE_FOLDER)/parsing/verify_map_close.c \
			./$(SOURCE_FOLDER)/parsing/verify_map.c \
			./$(SOURCE_FOLDER)/parsing/verify_type.c \
			./$(SOURCE_FOLDER)/minilibx/canva.c \
			./$(SOURCE_FOLDER)/minilibx/keep_in_map.c \
			./$(SOURCE_FOLDER)/minilibx/keyboard_actions.c \
			./$(SOURCE_FOLDER)/minilibx/libx_helper.c \
			./$(SOURCE_FOLDER)/minilibx/replace_tile.c \
			./$(SOURCE_FOLDER)/minilibx/sprites.c \
			./$(SOURCE_FOLDER)/minilibx/stop.c \

OBJETS	=	$(SOURCES:.c=.o)			


all		:  lib $(NAME)
	@echo "$(GREEN)Bien compilé ! Plus qu'a executer ./solong !$(RESET)"

$(MLX):
	make -C minilibx-linux

%.o: %.c
	@echo "Creation du .o $@"
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(MLX) $(OBJETS)
	@echo "\nCréation de l'executable solong\n"
	@$(CC) $(OBJETS) -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(MATH_LIB) $(GNL) $(PRINTF) $(LIBFT)

lib	: 
	@echo "Je déclenche le Makefile de Libft-plus\n"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) all
	@echo "Je sors du Makefile de Libft-plus"


clean	:
	@$(RM) $(OBJETS)


fclean	:	clean
	@echo "Suppression de $(NAME)"
	@$(RM) $(NAME)
	@echo "Suppression de a.out au cas ou"
	@$(RM) a.out
	@echo "Je rentre dans la librairie libft-plus"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) fclean
	@echo "Je sors de la librairie libft-plus"
	@echo "\n$(GREEN)Tout les fichiers ont bien été effacés$(RESET)\n"
	@echo "Suppression de tout les fichiers ajoutés par l'utilisateur\n"


re		:	fclean all