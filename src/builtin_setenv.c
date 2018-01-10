/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 00:38:57 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/10 02:48:29 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "header.h"

static void	get_name_value(char *arg, char **name, char **value)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		++i;
	if (i == 0)
		return ;
	if ((*name = ft_strndup(arg, i)) == NULL)
		err_exit("Error ft_strndup");
	if (arg[i] == '=')
	{
		++i;
		if ((*value = ft_strdup(arg + i)) == NULL)
			err_exit("Error ft_strdup");
	}
}

static void set_env(char *arg, t_env_lst **env_lst)
{
	char	*name;
	char	*value;

	name = NULL;
	value = NULL;
	get_name_value(arg, &name, &value);
	if (value != NULL)
		env_lst_set_value(name, value, env_lst);
	ft_strdel(&name);
	ft_strdel(&value);
}

int			builtin_setenv(char **argv)
{
	(void)argv;
	t_env_lst	**env_lst;
	char		**arg;

	env_lst = env_lst_sta(NULL);
	if (env_lst == NULL)
		err_exit("Error env_lst_sta");
	arg = argv;
	while (*arg != NULL)
	{
		set_env(*arg, env_lst);
		++arg;
	}
	return (0);
}
