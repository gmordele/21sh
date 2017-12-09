/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 05:20:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 05:38:40 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

t_redir	*parser_redir_in(char *n, t_token_lst **cur_token, int *error)
{
	char	*in_n;

	in_n = (n == NULL) ? ft_strdup("0") : ft_strdup(n);
	
}

static t_redir	*redir_type(char *n, t_token_lst **cur_token, int *error)
{
		t_redir	*redir;
		int		token_type;

		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
		if (token_type == LESS)
		{
			parser_eat(cur_token, WORD);
			redir = parser_redir_in(n, cur_token, error);
		}
		if (*error)
			return (NULL);
		return (redir);
}

t_redir			*parser_redir(char *n, t_token_lst **cur_token, int *error)
{
	int		token_type;
	t_redir	*redir;

	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	redir = redir_type(n, cur_token, error);
	if (*error)
		return (NULL);
	return (redir);
}
