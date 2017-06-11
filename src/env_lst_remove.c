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

static void	free_root(t_env_lst **root)
{
	t_env_lst *p;

	free((*root)->value);
	free((*root)->name);
	p = *root;
	*root = p->next;
	free(p);
}

static void	free_el(t_env_lst *prev, t_env_lst *el)
{
	free(el->name);
	free(el->value);
	prev->next = el->next;
	free(el);
}

int			env_lst_remove(t_env_lst **root, char *name)
{
	t_env_lst	*p;
	t_env_lst	*p_next;

	if (root == NULL || *root == NULL || name == NULL)
		return (-1);
	if (ft_strequ(name, (*root)->name))
	{
		free_root(root);
		return (0);
	}
	p = *root;
	p_next = (*root)->next;
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
