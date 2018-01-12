/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:48 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/12 20:34:16 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <sys/param.h>
#include "header.h"
#include "libft.h"

static void	cd_error(char *path)
{
	ft_dprintf(2, "21sh: cd: %s: ", path);
	if (errno == EACCES)
		ft_dprintf(2, "Permission denied");
	else if (errno == ENAMETOOLONG)
		ft_dprintf(2, "File name too long");
	else if (errno == ENOENT)
		ft_dprintf(2, "No such file or directory");
	else if (errno == ENOTDIR)
		ft_dprintf(2, "Not a directory");
	else
		ft_dprintf(2, "Unknown error");
	ft_dprintf(2, "\n");
}

static int	change_dir(char *path)
{
	char		new_dir[MAXPATHLEN];
	t_env_lst	**env_lst;
	char		*pwd;

	if (chdir(path) != 0)
	{
		cd_error(path);
		return (1);
	}
	else
	{
		if (getcwd(new_dir, MAXPATHLEN) != NULL)
		{
			if ((env_lst = env_lst_sta(NULL)) == NULL)
				err_exit("Error env_lst_sta");
			if ((pwd = env_lst_get_value("PWD")) != NULL)
				env_lst_set_value("OLDPWD", pwd, env_lst);
			env_lst_set_value("PWD", new_dir, env_lst);
		}
	}
	return (0);
}

int			builtin_cd(char **argv, char **env)
{
	char	*path;

	(void)env;
	if (argv == NULL || *argv == NULL)
		return (1);
	++argv;
	if (*argv == NULL)
	{
		if ((path = env_lst_get_value("HOME")) == NULL)
		{
			ft_dprintf(2, "21sh: cd: HOME not set\n");
			return (1);
		}
	}
	else if (!ft_strcmp(*argv, "-"))
	{
		if ((path = env_lst_get_value("OLDPWD")) == NULL)
		{
			ft_dprintf(2, "21sh: cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
		path = *argv;
	return (change_dir(path));
}
