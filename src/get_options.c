/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:26:01 by gmordele          #+#    #+#             */
/*   Updated: 2017/11/16 03:32:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_option(char c)
{
	if (c == 'k')
		return (OPT_KEYS);
	if (c == 'd')
		return (OPT_DEBUG);
	if (c == 'h')
		return (OPT_HELP);
	return (0);
}

int			get_options(int argc, char **argv)
{
	int		options;
	char	c;

	options = 0;
	while (--argc > 0 && **(++argv) == '-')
		while ((c = *(++(*argv))) != '\0')
			options |= get_option(c);
	return (options);
}
