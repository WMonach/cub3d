NAME =		cub3d

CFLAGS =	-Wall -Wextra -I$(LIBFT_DIR) -I$(INC_DIR) -Imlx/ #-fsanitize=address -g

CFLAGS =	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INC_DIR) -Isources/get_next_line/ -Imlx/ #-fsanitize=address -g

CC =		gcc

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
					cub/draw								\
					utils/round								\
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


# /***** MAKEFILE FOR LINUX *****/
# NAME =		cub3d

# CFLAGS =	-Wall -Wextra -Werror -I . #-fsanitize=address -g

# CC =		gcc

# LIBFT_DIR =	libft/

# MLBX_DIR = mlx/

# OBJS_DIR = .objs

# OBJ =	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

# OBJ_BONUS = $(addprefix $(OBJS_DIR)/, $(FILES_BONUS:.c=.o))

# FILES = main.c			\

# FILES_BONUS =	\

# all: libs $(NAME)

# libs:
# 	$(MAKE) -C $(LIBFT_DIR)
# 	$(MAKE) -C $(MLBX_DIR)

# $(NAME):			$(OBJ) $(LIBFT_DIR)libft.a
# 					$(CC) $(SFLAG) $(OBJ) $(LIBFT_DIR)libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux  -lXext -lX11 -lm -lz-o $(NAME)
	
# $(OBJS_DIR)/%.o:	%.c cub3d.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a Makefile | $(OBJS_DIR)
# 					${CC} ${CFLAGS} -I$(LIBFT_DIR) -Imlx -O3 -c $< -o $@

# $(OBJS_DIR):			
# 					mkdir $(OBJS_DIR)

# bonus :				libs $(OBJ_BONUS) $(LIBFT_DIR)libft.a
# 					$(CC) $(OBJ_BONUS) $(LIBFT_DIR)libft.a -o cub3d_bonus

# $(OBJS_DIR)/%.o:	%.c cub3d_bonus.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a ${MLBX_DIR}libmlx.a Makefile | $(OBJS_DIR)
# 					${CC} ${CFLAGS} -I$(LIBFT_DIR) -c $< -o $@

# norme :
# 					norminette srcs/*.c *.h

# clean :
# 					${MAKE} clean -C ${LIBFT_DIR}
# 					${MAKE} fclean -C ${MLBX_DIR}
# 					rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 
# 					rm -rf $(OBJS_DIR)

# fclean :
# 					${MAKE} fclean -C ${LIBFT_DIR}
# 					${MAKE} fclean -C ${MLBX_DIR}
# 					rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o
# 					rm -f ${NAME}
# 					rm -f cub3d_bonus
# 					rm -rf $(OBJS_DIR)

# re :				fclean all

# .PHONY:				all clean fclean libs re objs obj bonus
