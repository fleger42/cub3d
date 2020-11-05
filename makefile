NAME        = Cub3D

all: ${NAME}

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

HEAD = -I /usr/local/include/ -I include/ 

LIB = -L /usr/local/lib/ -L libft/ -lmlx -lm -lXext -lX11 -lbsd

SRCS_PATH= srcs/

OBJS_PATH= objs/

SRCS_NAME= ft_parsing.c ft_parsing_utils.c ft_struct_map.c ft_struct_player.c ft_struct_sprite.c		\
			ft_struct_win.c get_next_line.c get_next_line_utils.c main.c ft_save_bpm.c					\
			ft_parsing_utils2.c ft_parsing_utils3.c ft_utils.c ft_verif_map.c ft_draw.c 				\
			ft_input_player.c ft_raycasting.c ft_spritecasting.c ft_texture.c ft_keys_move.c 			\
			ft_keys_view.c ft_math_sprite.c ft_sort_sprite.c
OBJS_NAME= $(SRCS_NAME:.c=.o)

SRCS= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS= $(addprefix $(OBJS_PATH), $(OBJS_NAME))

RED= \033[31;1m
GRN= \033[32;1m
DEF= \033[0m

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${HEAD} ${LIB}
			@echo "$(RED)[cub3d] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@echo "$(RED)[cub3d] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)[cub3d] : $(DEF)Cleaning           $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[cub3d] : $(DEF)Full Cleaning       $(GRN)[OK]$(DEF)"

re: fclean all

.PHONY: re clean fclean all

