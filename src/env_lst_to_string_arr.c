/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_string_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:08:26 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/10 02:56:13 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static char	*env_to_string(t_env_lst env)
{
	char	*ret;
	size_t	name_len;
	size_t	value_len;

	name_len = ft_strlen(env.name);
	value_len = ft_strlen(env.value);
	if ((ret = (char *)malloc(name_len + value_len + 2)) == NULL)
		return (NULL);
	ft_strcpy(ret, env.name);
	ret[name_len] = '=';
	ft_strcpy(ret + name_len + 1, env.value);
	return (ret);
}

char		**env_lst_to_string_arr(void)
{
	size_t		lst_len;
	char		**string_arr;
	int			i;
	t_env_lst	*env_lst;
	t_env_lst	**p;

	env_lst = *env_lst_sta(NULL);
	if ((p = env_lst_sta(NULL)) == NULL)
		err_exit("Error env_lst_sta");
	env_lst = *p;
	lst_len = env_lst_len(env_lst);
	if ((string_arr = (char **)malloc(sizeof(char *) * (lst_len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (env_lst != NULL)
	{
		string_arr[i] = env_to_string(*env_lst);
		++i;
		env_lst = env_lst->next;
	}
	string_arr[i] = NULL;
	return (string_arr);
}
