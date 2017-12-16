/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:31:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/16 04:14:47 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

static t_heredoc_lst	*new_heredoc(char *word)
{
	t_heredoc_lst	*new;

	if ((new = malloc(sizeof(t_heredoc_lst))) == NULL)
		err_exit("Error malloc");
	new->next = NULL;
	new->word = ft_strdup(word);
	pipe(new->fildes);
	return (new);
}

void					heredoc_lst_free(t_heredoc_lst *heredoc_lst)
{
	if (heredoc_lst == NULL)
		return ;
	heredoc_lst_free(heredoc_lst->next);
	free(heredoc_lst->word);
	free(heredoc_lst);
}

void					heredoc_lst_add(t_heredoc_lst **heredoc_lst, char *word,
										int fildes[2])
{
	t_heredoc_lst	*p;
	t_heredoc_lst	*new;

	new = new_heredoc(word);
	if (heredoc_lst == NULL)
		err_exit("Error heredoc_lst_add");
	if (*heredoc_lst == NULL)
		*heredoc_lst = new;
	else
	{
		p = *heredoc_lst;
		while(p->next != NULL)
			p = p->next;
		p->next = new;
	}
	fildes[0] = new->fildes[0];
	fildes[1] = new->fildes[1];
}
