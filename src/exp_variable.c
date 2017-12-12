/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:54:25 by gmordele          #+#    #+#             */
/*   Updated: 2017/12/12 03:29:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "header.h"

static int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static void	skip_quote(char *str, int *end)
{
	if (str[*end] == '\0')
		return ;
	++(*end);
	while (str[*end] != '\'' && str[*end] != '\0')
		++(*end);
}

static void	handle_dollar(char *str, char **new, int *start, int *end)
{
	char	*tmp1;
	char	*tmp2;

	if (is_var_char(str[++(*end)]))
	{
		if ((tmp1 = ft_strndup(str + *start, *end - *start - 1)) == NULL)
			err_exit("Error ft_strndup");
		if ((tmp2 = ft_strjoin(*new, tmp1)) == NULL)
			err_exit("Error ft_strjoin");
		free(tmp1);
		free(*new);
		*new = tmp2;
		*start = *end;
		++(*end);
		while (is_var_char(str[*end]) && str[*end] != '\0')
			++(*end);
		if ((tmp1 = ft_strndup(str + *start, *end - *start)) == NULL)
			err_exit("Error ft_strndup");
		tmp2 = env_lst_get_value(tmp1);
		if (tmp2 != NULL)
			*new = ft_strjoinfree(*new, tmp2, 1);
		free(tmp1);
		*start = *end;
	}
}

char		*exp_variable(char *str)
{
	char	*new;
	int		start;
	int		end;
	char	*tmp;
	char	*tmp1;

	if ((new = ft_strnew(0)) == NULL)
		err_exit("Error ft_strnew");
	start = 0;
	end = 0;
	while (str[end] != '\0')
	{
		if (str[end] == '\'')
			skip_quote(str, &end);
		else if (str[end] == '$')
			handle_dollar(str, &new, &start, &end);
		else
			++end;
	}
	tmp = ft_strndup(str + start, end - start);
	tmp1 = ft_strjoin(new, tmp);
	free(tmp);
	free(new);
	new = tmp1;
	return (new);
}
