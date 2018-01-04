/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:42:55 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/04 01:35:47 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	get_tmp(char *tmp, char *cmd_buf)
{
	ft_strcpy(tmp, cmd_buf);
	while (*tmp != '\0')
	{
		if (*tmp == '\n')
		{
			*tmp = '\0';
			break ;
		}
		++tmp;
	}
}

int			heredoc_check(char **buf, char *cmd_buf,
							t_heredoc_lst *heredoc_lst)
{
	char	tmp[CMDBUFSIZE];

	get_tmp(tmp, cmd_buf);
	if (!ft_strcmp(tmp, heredoc_lst->word) || *cmd_buf == '\0')
	{
		write(heredoc_lst->fildes[1], *buf, ft_strlen(*buf));
		free(*buf);
		return (1);
	}
	else
	{
		if ((*buf = ft_strjoinfree(*buf, cmd_buf, 1)) == NULL)
			err_exit("Error ft_strjoinfree");
		return (0);
	}
}
