#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 00:00:01 by gmordele          #+#    #+#              #
#    Updated: 2017/10/29 22:35:36 by gmordele         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME				=	21sh

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

SRC				=	main.c				 			init_term.c							sta_term_info.c				\
					err_exit.c						cmd_handle_key_char.c				restore_term.c				\
					get_options.c					print_keys.c						init_termcap.c				\
					tputc.c							normal_exit.c						init_signals.c				\
					pressed_key.c					cmd_handle_key_backspace.c			insert_mode.c				\
					cmd_get.c						env_lst_remove.c					env_lst.c					\
					env_lst_get.c					env_lst_get_value.c					env_lst_set_value.c			\
					env_lst_sta.c					cmd_handle_key_return.c				cmd_insert_char.c			\
					cmd_move_cursor_right.c			cmd_move_cursor_left.c				cmd_remove_char.c			\
					cmd_prev_line_len.c				cmd_move_cursor_end.c				cmd_print_line.c			\
					cmd_move_prev_line.c			cmd_handle_key_delete.c				cmd_handle_key_shift_up.c	\
					cmd_handle_key_shift_down.c		cmd_next_line_len.c					cmd_handle_key_shift_left.c	\
					cmd_handle_key_shift_right.c	cmd_move_next_line.c				cmd_move_cursor_begin.c		\
					cmd_handle_key_ctrl_space.c		cmd_handle_key_ctrl_x.c				cmd_get_term_width.c		\
					cmd_handle_key_left.c			cmd_handle_key_right.c

OBJ				=	$(addprefix $(DEST_OBJ), $(SRC:%.c=%.o))

DEST_SRC		=	./src/

DEST_INC		=	./include/

DEST_OBJ		=	./obj/

HEADERS			=	$(DEST_INC) $(DEST_LIB)

DEST_LIB		=	./libft

LIBFT			=	$(DEST_LIB)/libft.a

all 			:	mklib $(NAME)

$(NAME)			:	mkdir_obj $(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I$(DEST_INC) -I$(DEST_LIB) -ltermcap

$(DEST_OBJ)%.o	:	$(DEST_SRC)%.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEST_INC) -I$(DEST_LIB)

mkdir_obj		:
	mkdir -p $(DEST_OBJ)

mklib			:
	make -C $(DEST_LIB)

clean			:
	rm -rf $(DEST_OBJ)

fclean			:	clean
	rm -f $(NAME)

re				:	fclean all

clean_lib		:
	rm -rf $(DEST_OBJ)
	make clean -C $(DEST_LIB)

fclean_lib		:	clean
	rm -f $(NAME)
	make fclean -C $(DEST_LIB)

re_lib			:	fclean_lib all

.PHONY:all clean fclean re mklib mkdir_obj
