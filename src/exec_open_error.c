/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 01:15:08 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 01:35:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"

void	exec_open_error(char *word)
{
	char	*str;

	if (errno == EACCES)
		str = "Permission denied";
	else if (errno == EEXIST)
		str = "File exists";
	else if (errno == EISDIR)
		str = "Is a directory";
	else if (errno == ENOENT)
		str = "No such file or directory";
	else if (errno == ENOTDIR)
		str = "Not a directory";
	else
		str = "Error open";
	ft_dprintf(2, "21sh: %s: %s\n", word, str);
	exit(1);
}
