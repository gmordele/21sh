/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_lst_sta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 04:00:55 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 19:13:12 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ast_lst	**ast_lst_sta(t_ast_lst **ast_lst, int freed)
{
	static t_ast_lst	**sta = NULL;

	if (freed == 1)
	{
		sta = NULL;
		return (NULL);
	}
	if (ast_lst != NULL)
	{
		sta = ast_lst;
		return (NULL);
	}
	return (sta);
}
