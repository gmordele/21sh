/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:10:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/26 20:17:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char	*env_lst_get_value(char *name)
{
	t_env_lst	**p;

	p = env_lst_sta(NULL);
	if (p == NULL || *p == NULL || name == NULL)
		return (NULL);
	while (*p != NULL)
	{
		if (ft_strequ(name, (*p)->name))
			return (ft_strdup((*p)->value));
		*p = (*p)->next;
	}
	return (NULL);
}
