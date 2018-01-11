/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:42:37 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 02:58:16 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

int				builtin_env(char **argv)
{
	t_env_lst	**env_lst;
	t_env_lst	*p;

	(void)argv;
	env_lst = env_lst_sta(NULL);
	if (env_lst == NULL)
		err_exit("Error env_lst_sta");
	p = *env_lst;
	while (p != NULL)
	{
		ft_printf("%s=%s\n", p->name, p->value);
		p = p->next;
	}
	return (0);
}
