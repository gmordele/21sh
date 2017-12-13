/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_save_restore_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:42:58 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/13 04:05:25 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

void	exec_save_fd(int fd[3])
{
	if ((fd[0] = dup2(0, 1000)) < 0)
		err_exit("Error dup2");
	if ((fd[1] = dup2(1, 1001)) < 0)
		err_exit("Error dup2");
	if ((fd[2] = dup2(2, 1002)) < 0)
		err_exit("Error dup2");
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
