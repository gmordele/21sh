/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:53:46 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/01 05:12:36 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

static char	*token_type2(int type)
{
	if (type == 13) 
		return ("LESS");
	return ("");
}

static char	*token_type(int type)
{
	if (type == 1) 
		return ("WORD");
	if (type == 2) 
		return ("IO_NUMBER");
	if (type == 3) 
		return ("AND_IF");
	if (type == 4) 
		return ("OR_IF");
	if (type == 5) 
		return ("DLESS");
	if (type == 6) 
		return ("DGREAT");
	if (type == 7) 
		return ("LESSAND");
	if (type == 8) 
		return ("GREATAND");
	if (type == 9) 
		return ("SEMI");
	if (type == 10) 
		return ("AND");
	if (type == 11) 
		return ("OR");
	if (type == 12) 
		return ("GREAT");
	return (token_type2(type));
}

void		token_lst_print(t_token_lst *token_lst)
{
	char	*type;

	while (token_lst != NULL)
	{
		type = token_type(token_lst->token->type);
		ft_printf("TOKEN:(%s, \"{MAG}%s{RES}\")\n", type,
				token_lst->token->value);
		token_lst = token_lst->next;
	}
}
