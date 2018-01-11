/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:08:36 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 02:39:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static int	unset_env(char *arg, t_env_lst **env_lst)
{
	if (env_lst_remove(env_lst, arg) < 0)
	{
		ft_dprintf(2, "unsetenv: argument not found: %s\n", arg);
		return (1);
	}
	return (0);
}

int			builtin_unsetenv(char **argv, char **env)
{
	t_env_lst	**env_lst;
	char		**arg;
	int			ret;

	(void)env;
	env_lst = env_lst_sta(NULL);
	if (env_lst == NULL)
		err_exit("Error env_lst_sta");
	if ((arg = argv) == NULL)
		return (1);
	++arg;
	if (*arg == NULL)
	{
		ret = 1;
		ft_dprintf(2, "unsetenv: not enough arguments \n");
	}
	else
		ret = 0;
	while (*arg != NULL)
	{
		if (unset_env(*arg, env_lst) == 1)
			ret = 1;
		++arg;
	}
	return (ret);
}
