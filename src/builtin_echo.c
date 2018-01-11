/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:50:19 by gmordele          #+#    #+#             */
/*   Updated: 2018/01/11 04:15:12 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"

static int	write_echo(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (write(1, arg, len) >= 0)
		return (1);
	return (0);
}

static int	print_error(void)
{
	if (errno == EBADF)
		ft_dprintf(2, "21sh: echo: write error: Bad file descriptor\n");
	else
		ft_dprintf(2, "21sh: echo: Unknown error\n");
	return (1);
}

int			builtin_echo(char **argv, char **env)
{
	int		start;

	(void)env;
	start = 1;
	if (*argv != NULL)
	{
		++argv;
		while (*argv != NULL)
		{
			if (start == 1)
				start = 0;
			else
			{
				if (!write_echo(" "))
					return (print_error());
			}
			if (!write_echo(*argv))
				return (print_error());
			++argv;
		}
	}
	if (!write_echo("\n"))
		return (print_error());
	return (0);
}
