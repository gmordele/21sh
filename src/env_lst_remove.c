/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:58:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 18:32:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	free_head(t_env_lst **head)
{
	t_env_lst *p;

	free((*head)->value);
	free((*head)->name);
	p = *head;
	*head = p->next;
	free(p);
}

static void	free_el(t_env_lst *prev, t_env_lst *el)
{
	free(el->name);
	free(el->value);
	prev->next = el->next;
	free(el);
}

int			env_lst_remove(t_env_lst **head, char *name)
{
	t_env_lst	*p;
	t_env_lst	*p_next;

	if (head == NULL || *head == NULL || name == NULL)
		return (-1);
	if (ft_strequ(name, (*head)->name))
	{
		free_head(head);
		return (0);
	}
	p = *head;
	p_next = (*head)->next;
	while (p_next != NULL)
	{
		if (ft_strequ(name, p_next->name))
		{
			free_el(p, p_next);
			return (0);
		}
		p = p_next;
		p_next = p_next->next;
	}
	return (-1);
}
