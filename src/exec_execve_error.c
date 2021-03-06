/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execve_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:31:13 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 00:41:47 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"

void		exec_execve_error(char *word)
{
	char	*strerr;

	if (errno == EACCES)
		strerr = "Permission denied";
	else if (errno == ENOENT)
		strerr = "No such file or directory";
	else if (errno == ENOEXEC)
		strerr = "Exec format error";
	else if (errno == ENOTDIR)
		strerr = "Not a directory";
	else
		strerr = "Error execve";
	ft_dprintf(2, "21sh: %s: %s\n", word, strerr);
}
