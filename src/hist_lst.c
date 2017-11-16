/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:53:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 23:31:57 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static t_hist_lst	*new_hist(t_hist_lst *prev, const char *cmd)
{
	t_hist_lst	*new;

	new = (t_hist_lst *)malloc(sizeof(t_hist_lst));
	if (new == NULL)
		err_exit("Error malloc");
	new->prev = prev;
	new->next = NULL;
	ft_memcpy(new->cmd, cmd, CMDBUFSIZE);
	ft_memcpy(new->cmd_unchanged, cmd, CMDBUFSIZE);
	return (new);
}

void				hist_lst_add(const char *cmd)
{
	t_hist_lst	**head;

	head = hist_lst_sta(NULL);
	if (head == NULL)
		err_exit("Error hist_lst_sta");
	if (*head == NULL)
		*head = new_hist(NULL, cmd);
	else
	{
		(*head)->next = new_hist(*head, cmd);
		*head = (*head)->next;
	}
}

t_hist_lst			**hist_lst_sta(t_hist_lst **head_hist)
{
	static t_hist_lst **sta_head_hist = NULL;

	if (head_hist != NULL)
		sta_head_hist = head_hist;
	return (sta_head_hist);
}

void				hist_lst_free(void)
{
	t_hist_lst	**head;
	t_hist_lst	*prev;

	head = hist_lst_sta(NULL);
	if (head == NULL || *head == NULL)
		return ;
	while (*head != NULL)
	{
		prev = (*head)->prev;
		free(*head);
		*head = prev;
	}
}
