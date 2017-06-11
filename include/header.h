/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:09:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 17:49:09 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_HEADER_H
# define DEF_HEADER_H

# include <termios.h>

# define OPT_KEYS			1

# define CMDBUFSIZE			1024
# define READBUFSIZE		16

# define KEY_UP				1
# define KEY_DOWN			2
# define KEY_LEFT			3
# define KEY_RIGHT			4
# define KEY_BACKSPACE		5
# define KEY_ESCAPE			6

typedef struct	s_term_info
{
	struct termios	saved_termios;
	int				is_saved;
}				t_term_info;

typedef struct	s_cmd
{
	
}				t_cmd;

t_term_info		*sta_term_info(t_term_info *term);
void			err_exit(char *str);
void			err_exit_rest(char *str);
void			restore_term(void);
void			init_termios(t_term_info *term);
void			init_termcap(void);
int				get_options(int argc, char **argv);
void			print_keys(void);
int				tputc(int c);
void			normal_exit(void);
void			init_signals(void);
int				pressed_key(int n, char *read_buf);
void			move_cursor_right(void);
void			move_cursor_left(void);
void			enter_insert(void);
void			exit_insert(void);
int				get_cmd(char *cmd_buf, int prompt_size);

#endif
