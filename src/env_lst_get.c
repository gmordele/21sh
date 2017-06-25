/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 00:08:00 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 16:18:40 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"
#include <stdio.h>
void	env_lst_get(void)
{
	extern char			**environ;
	char				*equal_pos;
	char				*name_tmp;
	static t_env_lst	*env_lst = NULL;

	if (environ != NULL)
	{
		while (*environ != NULL)
		{
			equal_pos = ft_strchr(*environ, '=');
			if (equal_pos == NULL)
				break ;
			name_tmp = ft_strndup(*environ, equal_pos - *environ);
			if (name_tmp == NULL)
				break ;
			env_lst_add(&env_lst, name_tmp, equal_pos + 1);
			free(name_tmp);
			environ++;
		}
	}
	env_lst_sta(&env_lst);
}
