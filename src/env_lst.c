/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 23:21:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 16:19:03 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "header.h"

void		env_lst_free(void)
{
	t_env_lst *p1;
	t_env_lst *p2;
	t_env_lst **env_lst;

	env_lst = env_lst_sta(NULL);
	if (env_lst == NULL || *env_lst == NULL)
		return ;
	p1 = *env_lst;
	while (p1 != NULL)
	{
		p2 = p1->next;
		ft_strdel(&(p1->name));
		ft_strdel(&(p1->value));
		free(p1);
		p1 = p2;
	}
	*env_lst = NULL;
}

size_t		env_lst_len(t_env_lst *env_lst)
{
	int	len;

	len = 0;
	while (env_lst != NULL)
	{
		++len;
		env_lst = env_lst->next;
	}
	return (len);
}

t_env_lst	*env_lst_new(char *name, char *value)
{
	t_env_lst	*ret;

	if (name == NULL || value == NULL)
		return (NULL);
	if ((ret = malloc(sizeof(t_env_lst))) == NULL)
		err_exit("Error malloc");
	ret->name = ft_strdup(name);
	ret->value = ft_strdup(value);
	ret->next = NULL;
	return (ret);
}

void		env_lst_add(t_env_lst **head, char *name, char *value)
{
	t_env_lst	*p;

	if (head == NULL || name == NULL || value == NULL)
		return ;
	if (*head == NULL)
		*head = env_lst_new(name, value);
	else
	{
		p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = env_lst_new(name, value);
	}
}
