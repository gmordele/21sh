#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 00:00:01 by gmordele          #+#    #+#              #
#    Updated: 2017/06/25 15:50:40 by gmordele         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	21sh

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	main.c				init_term.c			sta_term_info.c		\
				err_exit.c					restore_term.c		\
				get_options.c		print_keys.c		init_termcap.c		\
				tputc.c				normal_exit.c		init_signals.c		\
				pressed_key.c		move_cursor.c		insert_mode.c		\
				get_cmd.c			env_lst_remove.c	env_lst.c			\
				env_lst_get.c		env_lst_get_value.c	env_lst_set_value.c	\
				env_lst_sta.c

OBJ			=	$(SRC:%.c=%.o)

DEST_SRC	=	./src/

DEST_INC	=	./include/

HEADERS		=	$(DEST_INC) $(DEST_LIB)

DEST_LIB	=	./libft

LIBFT		=	$(DEST_LIB)/libft.a

all 		:	mklib $(NAME)

$(NAME)		:	$(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I$(DEST_INC) -I$(DEST_LIB) -ltermcap

%.o			:	$(DEST_SRC)%.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEST_INC) -I$(DEST_LIB)

mklib		:
	make -C $(DEST_LIB) 

clean		:
	rm -f $(OBJ)
	make clean -C $(DEST_LIB)

fclean		:	clean
	rm -f $(NAME)
	make fclean -C $(DEST_LIB)

re			:	fclean all

.PHONY:all clean fclean re mklib
