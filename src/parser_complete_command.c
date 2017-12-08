/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_complete_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:02:12 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 05:43:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ast_lst		*parser_complete_command(t_token_lst **cur_token, int *error)
{
	t_ast_lst	*list;

	list = parser_list(cur_token, error);
	if (cur_token != NULL)
	{
		if (!parser_eat(cur_token, SEMI))
			*error = 1;
		else if (cur_token != NULL)
			*error = 1;
	}
	return (list);
}
