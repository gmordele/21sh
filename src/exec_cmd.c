/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 02:37:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/10 03:02:51 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "header.h"

int		exec_cmd(t_ast_cmd_node cmd_node)
{
	int		fildes[2];
	int		fd_in;
	t_pid	pid;
	int		n_exec;

	return 0;
}
