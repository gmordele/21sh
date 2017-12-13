/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle_redir_bi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 04:11:44 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/13 04:17:36 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

int		exec_handle_redir_in_bi(char *n, char *word)
{
	int		fd;

	fd = open(word, O_RDONLY);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		return (0);
	}
	return (1);
}

int		exec_handle_redir_out_bi(char *n, char *word)
{
	int		fd;

	fd = open(word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		return (0);
	}
	return (1);
}

int		exec_handle_redir_out_app_bi(char *n, char *word)
{
	int		fd;

	fd = open(word, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		return (0);
	}
	return (1);
}

int		exec_handle_redir_dup_bi(char *n, char *word)
{
	if (ft_strcmp("-", word) == 0)
	{
		close(ft_atoi(n));
		return (1);
	}
	if (!exec_redir_is_num(word))
	{
		ft_dprintf(2, "21sh: %s: ambiguous redirect\n", word);
		return (0);
	}
	if (dup2(ft_atoi(word), ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		return (0);
	}
	return (1);
}
