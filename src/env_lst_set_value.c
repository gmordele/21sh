/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:49:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/03/29 18:14:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	set_value(char *name, char *value, t_env_lst **env_lst)
{
	t_env_lst	*p;

	if (*env_lst == NULL)
	{
		env_lst_add(env_lst, name, value);
		return ;
	}
	p = *env_lst;
	while (p->next != NULL)
	{
		if (ft_strequ(name, p->name))
		{
			ft_strdel(&(p->value));
			p->value = ft_strdup(value);
			return ;
		}
		p = p->next;
	}
	if (ft_strequ(name, p->name))
	{
		ft_strdel(&(p->value));
		p->value = ft_strdup(value);
		return ;
	}
	p->next = env_lst_new(name, value);
}

void		env_lst_set_value(char *name, char *value, t_env_lst **env_lst)
{
	if (name != NULL && value != NULL && env_lst != NULL)
		set_value(name, value, env_lst);
}
