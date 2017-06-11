/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sta_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:42:40 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/11 19:31:50 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_env_lst	**sta_env_lst(t_env_lst **head_env)
{
	static t_env_lst	**sta_head_env = NULL;

	if (head_env == NULL)
	{
		if (sta_head_env == NULL)
			err_exit("Error sta_env_lst");
	}
	else
		sta_head_env = head_env;
	return (sta_head_env);
}
