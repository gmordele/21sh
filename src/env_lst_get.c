/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 00:08:00 by gmordele          #+#    #+#             */
/*   Updated: 2017/10/29 21:43:48 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void	env_lst_get(void)
{
	extern char			**environ;
	char				**tmp_env;
	char				*equal_pos;
	char				*name_tmp;
	static t_env_lst	*env_lst = NULL;

	if ((tmp_env = environ) != NULL)
	{
		while (*tmp_env != NULL)
		{
			equal_pos = ft_strchr(*tmp_env, '=');
			if (equal_pos == NULL)
				break ;
			name_tmp = ft_strndup(*tmp_env, equal_pos - *tmp_env);
			if (name_tmp == NULL)
				break ;
			env_lst_add(&env_lst, name_tmp, equal_pos + 1);
			free(name_tmp);
			tmp_env++;
		}
	}
	env_lst_sta(&env_lst);
}
