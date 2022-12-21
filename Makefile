NAME =		cub3d

CFLAGS =	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INC_DIR) -Isources/get_next_line/ -Imlx/

CC =		gcc

CRASH = -fsanitize=address -g3

INC_DIR = includes/

DIR_OBJ =	.object

SUB_DIR_LST =	cub srcs utils includes parsing get_next_line

CUB_DIR =	$(INC_DIR)cub3d.h

LIBFT_DIR =	$(INC_DIR)libft/

MD := mkdir -p

DIR_SRC := sources#.

FILE_EXT := .c

OBJ			=		$(addprefix $(DIR_OBJ)/, $(addsuffix .o,$(INC_FILES)))

SUB_DIR=			$(addprefix $(DIR_OBJ)/,$(SUB_DIR_LST))

INC_FILES	=		cub/main								\
					cub/main_function						\
					cub/draw								\
					cub/main_utils							\
					cub/free_functions						\
					cub/keyhook_and_rotation				\
					cub/key_hook_and_rotation_utils			\
					cub/map_display							\
					cub/ray_and_wall_print					\
					cub/ray_shooting_utils					\
					cub/vertical_line_check_utils			\
					cub/horizontal_line_check_utils			\
					cub/draw_utils							\
					cub/print_game_utils					\
					parsing/check_id_utils					\
					parsing/check_id						\
					parsing/line_parsing_utils				\
					parsing/line_parsing					\
					parsing/map_parsing						\
					parsing/map_wall_parsing_utils			\
					parsing/map_wall_parsing				\
					parsing/parsing_utils					\
					parsing/parsing							\
					parsing/rgb_parsing						\
					parsing/save_textures					\
					parsing/spawn_checking					\
					parsing/save_textures_utils				\
					get_next_line/get_next_line				\
					get_next_line/get_next_line_utils

all: 				libs $(NAME)

libs:
					$(MAKE) -C $(LIBFT_DIR)
					$(MAKE) -C mlx/

$(NAME):			$(OBJ) $(LIBFT_DIR)libft.a
					$(CC) $(OBJ) $(LIBFT_DIR)libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
$(DIR_OBJ)/%.o:		$(DIR_SRC)/%$(FILE_EXT) includes/cub3d.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a Makefile | $(SUB_DIR)
					${CC} ${CFLAGS} -c $< -o $@

$(SUB_DIR) :
					$(MD) $@

bonus :				libs $(OBJ_BONUS) $(LIBFT_DIR)libft.a
					$(CC) $(OBJ_BONUS) $(LIBFT_DIR)libft.a -o cub3d_bonus

# $(DIR_OBJ)/%.o:	%.c includes/cub3d_bonus.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a Makefile | $(SUB_DIR)
# 					${CC} ${CFLAGS} -I$(LIBFT_DIR) -c $< -o $@

norme :
					norminette srcs/*.c includes/*.c utils/*.c *.h includes/*.h

clean :
					${MAKE} clean -C ${LIBFT_DIR}
					${MAKE} clean -C mlx/
					rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 
					rm -rf $(OBJS_DIR)

fclean :
					${MAKE} fclean -C ${LIBFT_DIR}
					${MAKE} clean -C mlx/
					rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o
					rm -f ${NAME}
					rm -f cub3d_bonus
					rm -rf $(OBJS_DIR)

re :				fclean all

.PHONY:				all clean fclean libs re objs obj bonus
