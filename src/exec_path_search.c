/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:30:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:02:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "libft.h"

static char	*add_path(char *path, char *word)
{
	char	*search;
	int		i;
	int		j;

	if ((search = malloc(ft_strlen(path) + ft_strlen(word) + 2)) == NULL)
		err_exit("Error malloc");
	i = 0;
	while (path[i] != '\0')
	{
		search[i] = path[i];
		++i;
	}
	search[i++] = '/';
	j = 0;
	while ((search[i] = word[j]) != '\0')
	{
		++j;
		++i;
	}
	return (search);
}

char		*exec_path_search(char *word)
{
	char	*path;
	char	**arr;
	int		i;
	char	*search;
	char	*ret;

	path = env_lst_get_value("PATH");
	if (path == NULL)
		return (NULL);
	arr = ft_strsplit(path, ':');
	i = 0;
	ret = NULL;
	while (arr[i] != NULL)
	{
		search = add_path(arr[i++], word);
		if (access(search, F_OK) == 0)
		{
			ret = search;
			break ;
		}
		free(search);
	}
	free_string_arr(arr);
	return (ret);
}
