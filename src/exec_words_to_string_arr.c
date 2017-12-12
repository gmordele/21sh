/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_words_to_string_arr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:12:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:14:58 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static int	words_lst_len(t_word_lst *word_lst)
{
	int		len;

	len = 0;
	while (word_lst != NULL)
	{
		++len;
		word_lst = word_lst->next;
	}
	return (len);
}

char		**exec_words_to_string_arr(t_word_lst *word_lst)
{
	int		len;
	char	**arr;
	int		i;

	len = words_lst_len(word_lst);
	if ((arr = malloc(sizeof(char *) * (len + 1))) == NULL)
		err_exit("Error malloc");
	i = 0;
	while (word_lst != NULL)
	{
		arr[i++] = ft_strdup(word_lst->word);
		word_lst = word_lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
