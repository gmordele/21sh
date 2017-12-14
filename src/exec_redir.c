/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:53:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/14 02:36:14 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	handle_redir(t_redir *redir)
{
	if (redir->type == REDIR_IN)
		exec_handle_redir_in(redir->n, redir->word);
	else if (redir->type == REDIR_OUT)
		exec_handle_redir_out(redir->n, redir->word);
	else if (redir->type == REDIR_OUT_APP)
		exec_handle_redir_out_app(redir->n, redir->word);
	else if (redir->type == REDIR_DUP_OUT || redir->type == REDIR_DUP_IN)
		exec_handle_redir_dup(redir->n, redir->word);
}

void		exec_redir(t_redir_lst *redir_lst)
{
	t_redir	*redir;
	int		n;
	int		word_int;

	while (redir_lst != NULL)
	{
		redir = redir_lst->redir;
		n = ft_atoi(redir->n);
		word_int = ft_atoi(redir->word);
		if (n > 2 || word_int > 2)
		{
			ft_dprintf(2, "21sh: Bad file descriptor\n");
			exit(1);
		}
		handle_redir(redir);
		redir_lst = redir_lst->next;
	}
}
