/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_bi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 04:09:03 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/13 04:20:01 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static int	handle_redir_bi(t_redir *redir)
{
	if (redir->type == REDIR_IN)
		return (exec_handle_redir_in_bi(redir->n, redir->word));
	else if (redir->type == REDIR_OUT)
		return (exec_handle_redir_out_bi(redir->n, redir->word));
	else if (redir->type == REDIR_OUT_APP)
		return (exec_handle_redir_out_app_bi(redir->n, redir->word));
	else if (redir->type == REDIR_DUP_OUT || redir->type == REDIR_DUP_IN)
		return (exec_handle_redir_dup_bi(redir->n, redir->word));
	else
		return (0);
}

int		exec_redir_bi(t_redir_lst *redir_lst)
{
	t_redir	*redir;
	int		n;

	while (redir_lst != NULL)
	{
		redir = redir_lst->redir;
		n = ft_atoi(redir->n);
		if (n >= 4860)
		{
			ft_dprintf(2, "21sh: Bad file descriptor\n");
			return (0);
		}
		if (!handle_redir_bi(redir))
			return (0);
		redir_lst = redir_lst->next;
	}
	return (1);
}
