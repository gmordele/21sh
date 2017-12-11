/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_save_restore_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:42:58 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/11 16:49:27 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	exec_save_fd(int fd[3])
{
	fd[0] = dup(0);
	fd[1] = dup(1);
	fd[2] = dup(2);
}

void	exec_restore_fd(int fd[3])
{
	if (dup2(fd[0], 0) < 0)
		err_exit("Error dup2");
	close(fd[0]);
	if (dup2(fd[1], 1) < 0)
		err_exit("Error dup2");
	close(fd[1]);
	if (dup2(fd[2], 2) < 0)
		err_exit("Error dup2");
	close(fd[2]);
}
