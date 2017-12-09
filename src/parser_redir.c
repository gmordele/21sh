/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 05:20:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/09 17:36:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static int		get_type(int token_type)
{
	if (token_type == LESS)
		return (REDIR_IN);
	if (token_type == GREAT)
		return (REDIR_OUT);
	if (token_type == DGREAT)
		return (REDIR_OUT_APP);
	if (token_type == DLESS)
		return (REDIR_HERE);
	if (token_type == LESSAND)
		return (REDIR_DUP_IN);
	if (token_type == GREATAND)
		return (REDIR_DUP_OUT);
	else
	{
		err_exit("Error get_type");
		return (0);
	}
}

static char		*get_n(char *n, int token_type)
{
	char	*ret_n;
	
	if (n != NULL)
	{
		if ((ret_n = ft_strdup(n)) == NULL)
			err_exit("Error ft_strdup");
	}
	else
	{
		if (token_type == LESS || token_type == DLESS
			|| token_type == LESSAND)
		{
			if ((ret_n = ft_strdup("0")) == NULL)
				err_exit("Error ft_strdup");
		}
		else
		{
			if ((ret_n = ft_strdup("1")) == NULL)
				err_exit("Error ft_strdup");
		}
	}
	return (ret_n);
}

static char		*exp_word(char *word, int type)
{
	char	*var_exp;
	char	*unquoted;

	if (type != REDIR_HERE)
	{
		var_exp = exp_variable(word);
		unquoted = exp_remove_quotes(var_exp);
		free(word);
		free(var_exp);
		return (unquoted);
	}
	unquoted = exp_remove_quotes(word);
	free(word);
	return (unquoted);
}

static t_redir	*get_redir(char *n, t_token_lst **cur_token, int *error)
{
		t_redir	*redir;
		int		token_type;
		char	*word;

		token_type = *cur_token == NULL ? EOF : (*cur_token)->token->type;
		parser_eat(cur_token, token_type);
		word = *cur_token == NULL ? NULL : (*cur_token)->token->value;
		if (!parser_eat(cur_token, WORD))
		{
			*error = 1;
			return (NULL);
		}
		if (word == NULL)
			err_exit("Error get_redir");
		if ((redir = malloc(sizeof(t_redir))) == NULL)
			err_exit("Error malloc");
		if ((redir->word = ft_strdup(word)) == NULL)
			err_exit("Error ft_strdup");
		redir->n = get_n(n, token_type);
		redir->type = get_type(token_type);
		redir->word = exp_word(redir->word, redir->type);
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
