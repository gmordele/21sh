/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_sta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:42:40 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/25 16:19:29 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_env_lst	**env_lst_sta(t_env_lst **head_env)
{
	static t_env_lst	**sta_head_env = NULL;

	if (head_env != NULL)
		sta_head_env = head_env;
	return (sta_head_env);
}
