/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:36:24 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/16 04:00:38 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
void		heredoc(t_heredoc_lst *heredoc_lst)
{
	while (heredoc_lst != NULL)
	{
		write(heredoc_lst->fildes[1], heredoc_lst->word, strlen(heredoc_lst->word));
		close(heredoc_lst->fildes[1]);
		heredoc_lst = heredoc_lst->next;
	}
}
