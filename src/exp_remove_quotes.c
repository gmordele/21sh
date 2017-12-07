/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_remove_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:54:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/07 03:13:19 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

char	*exp_remove_quotes(char *str)
{
	char	*new;
	int		i;
	char	c;

	if (str == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '"')
		{
			c = *str;
			++str;
			while (*str != c && *str != '\0')
			{
				new[i++] = *str;
				++str;
			}
			if (*str != '\0')
				++str;
		}
		else
			new[i++] = *(str++);
	}
	return (new);
}
