/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:06:42 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/08 05:45:48 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int		parser_eat(t_token_lst **cur_token, int token_type)
{
	if (cur_token == NULL)
		err_exit("Error parser_eat");
	if (*cur_token == NULL)
		return (0);
	if ((*cur_token)->token->type != token_type)
		return (0);
	*cur_token = (*cur_token)->next;
	return (1);
}
