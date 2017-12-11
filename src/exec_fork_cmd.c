#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "header.h"
#include "libft.h"

static void		cmd(t_exec_data *exec_data)
{
	char	*path;

	if (ft_strchr(exec_data->words[0], '/') != NULL)
	{
		execve(exec_data->words[0], exec_data->words, exec_data->env);
		exec_execve_error();
		exit(126);
	}
	path = exec_path_search(exec_data->words[0]);
	if (path == NULL)
	{
		ft_dprintf(2, "%s: command not found\n", exec_data->words[0]);
		exit(127);
	}
	execve(path, exec_data->words, exec_data->env);
	exec_execve_error();
	exit(127);
}

void			exec_fork_cmd(t_ast_cmd_node cmd_node, t_exec_data *exec_data)
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
		cmd(exec_data);
		execve(exec_data->words[0], exec_data->words, exec_data->env);
		exit(1);
	}
	else
	{
		close(exec_data->fildes[1]);
		exec_data->fd_in = exec_data->fildes[0];
	}
}
