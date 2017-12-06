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

	if (is_var_char(str[*end + 1]))
	{
		if ((tmp1 = ft_strndup(str, *end - *start)) == NULL)
			err_exit("Error ft_strndup");
		if ((tmp2 == ft_strjoin(*new, tmp1)) == NULL)
			err_exit("Error ft_strjoin");
		free(tmp1);
		free(new);
		new = tmp2;
		
	}
	else
		++(*end);
}

char		*exp_variable(char *str)
{
	char	*new;
	int		start;
	int		end;

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
			++end
	}
}
