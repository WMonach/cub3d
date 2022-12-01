NAME =		cub3d

CFLAGS =	-Wall -Wextra -Werror -I . #-fsanitize=address -g

CC =		gcc

INC_DIR = includes/

CUB_DIR =	$(INC_DIR)cub3d.h

LIBFT_DIR =	$(INC_DIR)libft/

MLBX_DIR = minilibx/

OBJS_DIR = .objs

UTILS_DIR = utils/


OBJ			=		$(addprefix $(OBJS_DIR)/, $(INC_DIR)$(INC_FILES:.c=.o) , $(SRCS_DIR)$(SRCS_FILES:.c=.o) , $(MLBX_DIR)$(MLBX_FILES:.c=.o) , $(UTILS_DIR)$(UTILS_FILES:.c=.o))

OBJ_BONUS	=		$(addprefix $(OBJS_DIR)/, $(INC_DIR)$(INC_FILES_BONUS:.c=.o) , $(SRCS_DIR)$(SRCS_FILES_BONUS:.c=.o) , $(MLBX_DIR)$(MLBX_FILES_BONUS:.c=.o) , $(UTILS_DIR)$(UTILS_FILES_BONUS:.c=.o))

INC_FILES		=\

SRCS_FILES		=		main.c			\

MLBX_FILES		=\

UTILS_FILES		=\

INC_FILES_BONUS		=\

SRCS_FILES_BONUS		=		main.c			\

MLBX_FILES_BONUS		=\

UTILS_FILES_BONUS		=\

all: 				libs $(NAME)

libs:
					$(MAKE) -C $(LIBFT_DIR)
					$(MAKE) -C $(MLBX_DIR)

$(NAME):			$(OBJ) $(LIBFT_DIR)libft.a
					$(CC) $(OBJ) $(LIBFT_DIR)libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
$(OBJS_DIR)/%.o:	%.c includes/cub3d.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a Makefile | $(OBJS_DIR)
					${CC} ${CFLAGS} -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR):			
					mkdir -p $(OBJS_DIR)

bonus :				libs $(OBJ_BONUS) $(LIBFT_DIR)libft.a
					$(CC) $(OBJ_BONUS) $(LIBFT_DIR)libft.a -o cub3d_bonus

$(OBJS_DIR)/%.o:	%.c includes/cub3d_bonus.h ${LIBFT_DIR}libft.h ${LIBFT_DIR}libft.a Makefile | $(OBJS_DIR)
					${CC} ${CFLAGS} -I$(LIBFT_DIR) -c $< -o $@

norme :
					norminette srcs/*.c *.h

clean :
					${MAKE} clean -C ${LIBFT_DIR}
					${MAKE} clean -C ${MLBX_DIR}
					rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 
					rm -rf $(OBJS_DIR)

fclean :
					${MAKE} fclean -C ${LIBFT_DIR}
					${MAKE} clean -C ${MLBX_DIR}
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

# MLBX_DIR = minilibx/

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
