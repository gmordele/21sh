/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handle_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 03:07:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/13 01:36:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

void		exec_handle_redir_in(char *n, char *word)
{
	int		fd;

	fd = open(word, O_RDONLY);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		exit(1);
	}
}

void		exec_handle_redir_out(char *n, char *word)
{
	int		fd;

	fd = open(word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		exit(1);
	}
}

void		exec_handle_redir_out_app(char *n, char *word)
{
	int		fd;

	fd = open(word, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		exec_open_error(word);
	if (dup2(fd, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		exit(1);
	}
}

void		exec_handle_redir_dup(char *n, char *word)
{
	int		int_word;

	if (ft_strcmp("-", word) == 0)
	{
		close(ft_atoi(n));
		return ;
	}
	if (!exec_redir_is_num(word))
	{
		ft_dprintf(2, "21sh: %s: ambiguous redirect\n", word);
		exit(1);
	}
	int_word = ft_atoi(word);
	if (int_word >= 1000 || dup2(int_word, ft_atoi(n)) < 0)
	{
		ft_dprintf(2, "21sh: Bad file descriptor\n");
		exit(1);
	}
}