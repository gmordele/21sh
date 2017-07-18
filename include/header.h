/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:09:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/07/18 17:47:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_HEADER_H
# define DEF_HEADER_H

# include <termios.h>
# include <string.h>

# define OPT_KEYS			1

# define CMDBUFSIZE			1024
# define READBUFSIZE		16

# define KEY_UP				1
# define KEY_DOWN			2
# define KEY_LEFT			3
# define KEY_RIGHT			4
# define KEY_BACKSPACE		5
# define KEY_ESCAPE			6
# define KEY_RETURN			10
# define KEY_S_UP			11
# define KEY_S_DOWN			12

# define MATCH_NO			0
# define MATCH_QUOTE		1
# define MATCH_DQOTE		2

typedef struct	s_term_info
{
	struct termios	saved_termios;
	int				is_saved;
}				t_term_info;

typedef struct	s_cmd_info
{
	int		prompt_len;
	int		cur_line;
	int		cur_col;
	int		complet;
	int		char_buf;
	int		buf_pos;
	char	*cmd_buf;
	int		nchar_buf;
}				t_cmd_info;

typedef struct	s_cmd
{
	int truc;
}				t_cmd;

typedef struct	s_env_lst
{
	char				*name;
	char				*value;
	struct s_env_lst	*next;
}				t_env_lst;

t_term_info		*sta_term_info(t_term_info *term);
void			err_exit(char *str);
void			restore_term(void);
void			init_termios(void);
void			init_termcap(void);
int				get_options(int argc, char **argv);
void			print_keys(void);
int				tputc(int c);
void			normal_exit(void);
void			init_signals(void);
int				pressed_key(int n, char *read_buf);
void			cmd_move_cursor_right(t_cmd_info *cmd_info);
void			cmd_move_cursor_left(t_cmd_info *cmd_info);
void			enter_insert(void);
int				exit_insert(void);
void			cmd_get(char *cmd_buf, int prompt_len);
int				env_lst_remove(t_env_lst **head, char *name);
void			env_lst_add(t_env_lst **head, char *name, char *value);
void			env_lst_get(void);
char			*env_lst_get_value(char *name);
t_env_lst		*env_lst_new(char *name, char *value);
size_t			env_lst_len(t_env_lst *env_lst);
void			env_lst_set_value(char *name, char *value, t_env_lst **env_lst);
void			env_lst_free(void);
t_env_lst		**env_lst_sta(t_env_lst **head_env);
void			cmd_handle_key_char(t_cmd_info *cmd_info, int key);
void			cmd_handle_char(t_cmd_info *cmd_info, int c);
void			cmd_handle_key_return(t_cmd_info *cmd_info);
void			cmd_insert_char(t_cmd_info *cmd_info, int c);
void			cmd_handle_key_backspace(t_cmd_info *cmd_info);
void			cmd_remove_char(t_cmd_info *cmd_info);
int				cmd_prev_line_len(t_cmd_info *cmd_info);
void			cmd_move_cursor_end(t_cmd_info *cmd_info);
int				cmd_print_line(char *s);
void			cmd_move_prev_line(t_cmd_info *cmd_info);

#endif
