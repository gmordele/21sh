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

static t_redir	*get_redir(char *n, t_token_lst **cur_token, int *error)
{
		t_redir	*redir;
		int		token_type;
		char	*word;

		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
		parser_eat(cur_token, token_type);
		if (!parser_eat(cur_token, WORD))
		{
			*error = 1;
			return (NULL);
		}
		if ((word = (*cur_token)->token->value) == NULL)
			err_exit("Error get_redir");
		return (redir);
}

t_redir			*parser_redir(char *n, t_token_lst **cur_token, int *error)
{
	int		token_type;
	t_redir	*redir;

	token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
	redir = get_redir(n, cur_token, error);
	if (*error)
		return (NULL);
	return (redir);
}
