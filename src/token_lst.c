/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:03:38 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/01 02:37:12 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "header.h"

static t_token_lst	*token_lst_new(t_token *token)
{
	t_token_lst	*new;

	new = (t_token_lst *)malloc(sizeof(t_token_lst));
	if (new == NULL)
		err_exit("Error token_lst_new");
	new->token = token;
	new->next = NULL;
	return (new);
}

void				token_lst_add(t_token_lst **token_lst, t_token *token)
{
	t_token_lst	*p;

	if (token == NULL || token_lst == NULL)
		err_exit("Error token_lst_add");
	if (*token_lst == NULL)
		*token_lst = token_lst_new(token);
	else
	{
		p = *token_lst;
		while (p->next != NULL)
			p = p->next;
		p->next = token_lst_new(token);
	}
}

static void			free_token(t_token *token)
{
	if (token == NULL)
		err_exit("Error free_token");
	ft_strdel(&(token->value));
	free(token);
}

void				token_lst_free(t_token_lst **token_lst)
{
	t_token_lst	*p;
	t_token_lst	*next;

	if (token_lst == NULL || *token_lst == NULL)
		return ;
	p = *token_lst;
	while ((next = p->next) != NULL)
	{
		free_token(p->token);
		free(p);
		p = next;
	}
	free_token(p->token);
	free(p);
}
