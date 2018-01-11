/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 00:38:57 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 02:59:30 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "header.h"

static int	valid_name(char *name)
{
	if (*name == '\0' || ft_isdigit(*name))
		return (0);
	while (*name != '\0')
	{
		if (*name != '_' && !ft_isalnum(*name))
			return (0);
		++name;
	}
	return (1);
}

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
	if (!valid_name(*name))
		return ;
	if (arg[i] == '=')
	{
		++i;
		if ((*value = ft_strdup(arg + i)) == NULL)
			err_exit("Error ft_strdup");
	}
}

static int	set_env(char *arg, t_env_lst **env_lst)
{
	char	*name;
	char	*value;
	int		ret;

	name = NULL;
	value = NULL;
	get_name_value(arg, &name, &value);
	if (value != NULL)
	{
		ret = 0;
		env_lst_set_value(name, value, env_lst);
	}
	else
	{
		ft_dprintf(2, "setenv: invalid argument: `%s`\n", arg);
		ret = 1;
	}
	ft_strdel(&name);
	ft_strdel(&value);
	return (ret);
}

int			builtin_setenv(char **argv, char **env)
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
		ft_dprintf(2, "setenv: not enough arguments\n");
	}
	else
		ret = 0;
	while (*arg != NULL)
	{
		if (set_env(*arg, env_lst) == 1)
			ret = 1;
		++arg;
	}
	return (ret);
}
