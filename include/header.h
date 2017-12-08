/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:09:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 03:45:05 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_HEADER_H
# define DEF_HEADER_H

# include <termios.h>
# include <string.h>

# define OPT_KEYS			1
# define OPT_DEBUG			2
# define OPT_HELP			4

# define CMDBUFSIZE			1024
# define READBUFSIZE		16
# define HISTMAX			100
# define HISTRDBUFSIZE		1024

# define KEY_UP				1
# define KEY_DOWN			2
# define KEY_LEFT			3
# define KEY_RIGHT			4
# define KEY_BACKSPACE		5
# define KEY_ESCAPE			6
# define KEY_RETURN			10
# define KEY_SHIFT_UP		11
# define KEY_SHIFT_DOWN		12
# define KEY_CTRL_D			13
# define KEY_DELETE			14
# define KEY_SHIFT_LEFT		15
# define KEY_SHIFT_RIGHT	16
# define KEY_CTRL_F			17
# define KEY_CTRL_B			18
# define KEY_HOME			19
# define KEY_END			20
# define KEY_CTRL_A			21
# define KEY_CTRL_E			22
# define KEY_CTRL_SPACE		23
# define KEY_CTRL_X			24
# define KEY_CTRL_G			25
# define KEY_ALT_W			26
# define KEY_CTRL_Y			27
# define KEY_CTRL_W			28
# define KEY_CTRL_P			29
# define KEY_CTRL_N			30
# define KEY_CTRL_L			31
# define KEY_CTRL_K			200
# define KEY_CTRL_U			201

# define WORD				1
# define IO_NUMBER			2
# define AND_IF				3
# define OR_IF				4
# define DLESS				5
# define DGREAT				6
# define LESSAND			7
# define GREATAND			8
# define SEMI				9
# define AND				10
# define OR					11
# define GREAT				12
# define LESS				13

# define CMD_NODE			1
# define ANDOR_NODE			2

typedef struct	s_term_info
{
	struct termios	saved_termios;
	int				is_saved;
}				t_term_info;

typedef struct	s_hist_lst
{
	char				cmd[CMDBUFSIZE];
	char				cmd_unchanged[CMDBUFSIZE];
	struct s_hist_lst	*next;
	struct s_hist_lst	*prev;
}				t_hist_lst;

typedef struct	s_cmd_info
{
	int				options;
	int				prompt_len;
	int				cur_line;
	int				cur_col;
	int				complet;
	int				char_buf;
	int				buf_pos;
	char			*cmd_buf;
	int				nchar_buf;
	unsigned short	term_width;
	int				in_clipboard;
	int				clip1;
	int				clip2;
	char			clip_buf[CMDBUFSIZE];
	t_hist_lst		*hist_lst;
	int				in_main_buf;
	char			main_buf[CMDBUFSIZE];
}				t_cmd_info;

typedef struct	s_env_lst
{
	char				*name;
	char				*value;
	struct s_env_lst	*next;
}				t_env_lst;

typedef struct	s_token
{
	int					type;
	char				*value;
}				t_token;

typedef struct	s_token_lst
{
	t_token				*token;
	struct s_token_lst	*next;
}				t_token_lst;

typedef struct	s_word_lst
{
	char				*word;
	struct s_word_lst	*next;
}				t_word_lst;

typedef struct	s_redir_in
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_in;

typedef struct	s_redir_out
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_out;

typedef struct	s_redir_out_app
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_out_app;

typedef struct	s_redir_heredoc
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_heredoc;

typedef struct	s_redir_dup_out
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_dup_out;

typedef struct	s_redir_dup_in
{
	int		type;
	char	*n;
	char	*word;
}				t_redir_dup_in;

typedef union	u_redir
{
	int					type;
	t_redir_in			redir_in;
	t_redir_out			redir_out;
	t_redir_out_app		redir_out_add;
	t_redir_heredoc		redir_heredoc;
	t_redir_dup_out		redir_dup_out;
	t_redir_dup_in		redir_dup_in;
}				t_redir;

typedef struct	s_redir_lst
{
	t_redir				redir;
	struct s_redir_lst	*next;
}				t_redir_lst;

typedef struct	s_ast_cmd_node
{
	int						type;
	t_word_lst				*word_lst;
	t_redir_lst				*redir_lst;
	struct s_ast_cmd_node	*next_pipe;
}				t_ast_cmd_node;

typedef struct	s_ast_andor_node
{
	int					type;
	union u_ast_node	*left;
	union u_ast_node	*right;
}				t_ast_andor_node;

typedef struct	s_ast_list
{
	union u_ast_node	*ast_node;
	struct s_ast_list	*next;
}				t_ast_lst;

typedef union	u_ast_node
{
	int					type;
	t_ast_cmd_node		*ast_cmd_node;
	t_ast_andor_node	*ast_andor_node;
}				t_ast_node;

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
int				cmd_pressed_key(int n, char *read_buf);
void			cmd_move_cursor_right(t_cmd_info *cmd_info);
void			cmd_move_cursor_left(t_cmd_info *cmd_info);
void			cmd_get(char *cmd_buf, int prompt_len, int options);
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
void			cmd_insert_char(t_cmd_info *cmd_info, char c);
void			cmd_handle_key_backspace(t_cmd_info *cmd_info);
void			cmd_remove_char(t_cmd_info *cmd_info);
int				cmd_prev_line_len(t_cmd_info *cmd_info);
void			cmd_move_cursor_end(t_cmd_info *cmd_info);
void			cmd_handle_key_delete(t_cmd_info *cmd_info);
void			cmd_handle_key_shift_up(t_cmd_info *cmd_info);
void			cmd_handle_key_shift_down(t_cmd_info *cmd_info);
void			cmd_handle_key_shift_left(t_cmd_info *cmd_info);
void			cmd_handle_key_shift_right(t_cmd_info *cmd_info);
void			cmd_move_cursor_begin(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_space(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_x(t_cmd_info *cmd_info);
unsigned short	cmd_get_term_width(void);
void			cmd_handle_key_left(t_cmd_info *cmd_info);
void			cmd_handle_key_right(t_cmd_info *cmd_info);
void			cmd_print_characters(t_cmd_info *cmd_info);
void			cmd_move_down(void);
void			cmd_show_cursor(void);
void			cmd_hide_cursor(void);
void			cmd_delete_characters(t_cmd_info *cmd_info);
int				cmd_pressed_key_n_1(char *read_buf);
int				cmd_pressed_key_n_3(char *read_buf);
int				cmd_pressed_key_n_4(char *read_buf);
int				cmd_pressed_key_n_6(char *read_buf);
void			cmd_handle_key_ctrl_a(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_e(t_cmd_info *cmd_info);
void			cmd_enter_clipboard(t_cmd_info *cmd_info);
void			cmd_exit_clipboard(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_g(t_cmd_info *cmd_info);
void			cmd_handle_key_alt_w(t_cmd_info *cmd_info);
void			cmd_copy_clipboard(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_y(t_cmd_info *cmd_info);
void			cmd_insert_n_char(t_cmd_info *cmd_info, char *src, int n);
void			cmd_handle_key_ctrl_w(t_cmd_info *cmd_info);
void			cmd_remove_n_char(t_cmd_info *cmd_info, int n);
void			hist_lst_free(void);
t_hist_lst		**hist_lst_sta(t_hist_lst **head_hist);
void			hist_lst_add(const char *cmd);
void			hist_lst_init(void);
void			cmd_handle_key_up(t_cmd_info *cmd_info);
void			cmd_change_buf(t_cmd_info *cmd_info, char *cpy_buf,
							char *save_buf);
void			cmd_handle_key_down(t_cmd_info *cmd_info);
void			hist_lst_save(void);
void			hist_lst_get(void);
int				print_prompt(void);
void			cmd_info_init(t_cmd_info *cmd_info, int prompt_len,
							char *cmd_buf, int options);
t_cmd_info		*cmd_info_sta(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_l(t_cmd_info *cmd_info);
void			sigint_handler(int sig);
void			sigwinch_handler(int sig);
void			cmd_handle_key_ctrl_k(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_u(t_cmd_info *cmd_info);
void			cmd_handle_key_ctrl_d(t_cmd_info *cmd_info);
void			print_help(void);
t_token_lst		*lexer(char *cmd);
void			token_lst_add(t_token_lst **token_lst, t_token *token);
void			token_lst_free(t_token_lst **token_lst);
int				lexer_is_op_char(char c);
t_token			*lexer_token_op(char **cmd);
t_token			*lexer_token_word(char **cmd);
t_token			*lexer_token_number(char **cmd);
void			token_lst_print(t_token_lst *token_lst);
char			*exp_variable(char *str);
char			*exp_remove_quotes(char *str);

#endif
