/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:10:29 by gmordele          #+#    #+#             */
/*   Updated: 2017/10/29 21:58:14 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char	*env_lst_get_value(char *name)
{
	t_env_lst	**ret_sta;
	t_env_lst	*p;

	if (name == NULL)
		return (NULL);
	ret_sta = env_lst_sta(NULL);
	if (ret_sta == NULL)
		return (NULL);
	p = *ret_sta;
	if (p == NULL || name == NULL)
		return (NULL);
	while (p != NULL)
	{
		if (ft_strequ(name, p->name))
			return (p->value);
		p = p->next;
	}
	return (NULL);
}
