/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:10:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/03/29 01:17:15 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char	*env_lst_get_value(char *name, t_env_lst *env_lst)
{
	t_env_lst	*p;

	if (env_lst == NULL || name == NULL)
		return (NULL);
	p = env_lst;
	while (p != NULL)
	{
		if (ft_strequ(name, p->name))
			return (ft_strdup(p->value));
		p = p->next;
	}
	return (NULL);
}
