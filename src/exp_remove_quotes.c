/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_remove_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:54:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:45:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

static void	init(int *i, char **new, char *str)
{
	*i = 0;
	if ((*new = ft_strnew(ft_strlen(str))) == NULL)
		err_exit("Error malloc");
}

char		*exp_remove_quotes(char *str)
{
	char	*new;
	int		i;
	char	c;

	if (str == NULL)
		return (NULL);
	init(&i, &new, str);
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
