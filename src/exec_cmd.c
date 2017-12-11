/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 02:37:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/11 18:01:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"

static t_pbuiltin	get_builtin(char *word)
{
	static t_name_builtin 	name_builtin[] = {{"echo", builtin_echo}};
	int						i;
	int						size;

	i = 0;
	size = sizeof(name_builtin) / sizeof(name_builtin[0]);
	while (i < size)
	{
		if (ft_strcmp(word, name_builtin[i].name) == 0)
			return (name_builtin[i].pbuiltin);
		++i;
	}
	return (NULL);
}

static void			exec_builtin(t_pbuiltin pbuiltin, t_exec_data *exec_data)
{
	int	fd[3];

	exec_data->last_exec = EXEC_BUILTIN;
	exec_save_fd(fd);
	exec_data->bi_ret = pbuiltin(exec_data->words);
	exec_restore_fd(fd);
}

static t_exec_data	init_exec_data(void)
{
	t_exec_data	exec_data;

	exec_data.fd_in = 0;
	exec_data.n_exec = 0;
	exec_data.env = env_lst_to_string_arr();
	return (exec_data);
}

static void			cmd(t_ast_cmd_node cmd_node, t_exec_data *exec_data)
{
	exec_data->last_exec = EXEC_CMD;
	++(exec_data->n_exec);
	exec_data->last_pid = fork();
	if (exec_data->last_pid == 0)
	{
		close(exec_data->fildes[0]);
		dup2(exec_data->fd_in, 0);
		if (cmd_node.next_pipe != NULL)
			dup2(exec_data->fildes[1], 1);
		if (exec_data->words[0] == NULL)
			exit(0);
		execve(exec_data->words[0], exec_data->words, exec_data->env);
		err_exit("error execve");
	}
	else
	{
		close(exec_data->fildes[1]);
		exec_data->fd_in = exec_data->fildes[0];
	}
}

static int			wait_ret(t_exec_data exec_data)
{
	int		status;

	if (exec_data.last_exec == EXEC_CMD)
	{
		waitpid(exec_data.last_pid, &status, 0);
		while (--(exec_data.n_exec) > 0)
			wait(NULL);
		return (status);
	}
	while ((exec_data.n_exec)-- > 0)
		wait(NULL);
	return (exec_data.bi_ret);
}

int					exec_cmd(t_ast_cmd_node cmd_node)
{
	t_pbuiltin	pbuiltin;
	t_exec_data exec_data;

	exec_data = init_exec_data();
	restore_term();
	while (42)
	{
		exec_data.words = exec_words_to_string_arr(cmd_node.word_lst);
		pipe(exec_data.fildes);
		if (exec_data.words[0] != NULL &&
			(pbuiltin = get_builtin(exec_data.words[0])) != NULL)
			exec_builtin(pbuiltin, &exec_data);
		else
			cmd(cmd_node, &exec_data);
		free_string_arr(exec_data.words);
		if (cmd_node.next_pipe != NULL)
			cmd_node = cmd_node.next_pipe->ast_cmd_node;
		else
			break ;
	}
	free_string_arr(exec_data.env);
	init_termios();	
	return (wait_ret(exec_data));
}
