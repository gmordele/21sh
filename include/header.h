/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:09:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 19:19:09 by gmordele         ###   ########.fr       */
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

typedef struct	s_term_info
{
	struct termios	saved_termios;
	int				is_saved;
}				t_term_info;

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
int				exit_insert(void);
int				get_cmd(char *cmd_buf, int prompt_len);
int				env_lst_remove(t_env_lst **head, char *name);
void			env_lst_add(t_env_lst **head, char *name, char *value);
t_env_lst		*get_env_lst(void);
char			*env_lst_get_value(char *name, t_env_lst *env_lst);
t_env_lst		*env_lst_new(char *name, char *value);
size_t			env_lst_len(t_env_lst *env_lst);
void			env_lst_set_value(char *name, char *value, t_env_lst **env_lst);
void			env_lst_free(t_env_lst **env_lst);
t_env_lst		**sta_env_lst(t_env_lst **head_env);

#endif
