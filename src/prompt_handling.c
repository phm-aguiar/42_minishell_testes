/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:55:45 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/11 16:14:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_start_pipe(void)
{
	char	*str;

	str = get_core()->input;
	if (str[0] == '|')
		return (FALSE);
	return (TRUE);
}

t_bool	check_end_operators(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = ft_strlen(str) - 1;
	if (str[i] == '|' || str[i] == '>' || str[i] == '<' || (str[i] == '>'
			&& str[i - 1] == '>') || (str[i] == '<' && str[i - 1] == '<'))
		return (FALSE);
	return (TRUE);
}

t_bool	check_spaces_between_redirections(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_quotes(str, &i);
		if (str[i] == '>')
		{
			while (ft_isspace(str[++i]))
				;
			if (str[i] == '>' && str[i - 1] != '>')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_spaces_between_heredock(void)
{
	char	*str;
	int		i;

	str = get_core()->input;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			skip_quotes(str, &i);
		if (str[i] == '<')
		{
			while (ft_isspace(str[++i]))
				;
			if (str[i] == '<' && str[i - 1] != '<')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

char	*check_input_error(void)
{
	if (check_close_quotes() == FALSE)
		return ("syntax error: unexpected end of file");
	if (check_forbidden_or() == FALSE)
		return ("syntax error: unexpected token `||'");
	if (check_forbidden_and() == FALSE)
		return ("syntax error: unexpected token `&&'");
	if (check_forbidden_semicolon() == FALSE)
		return ("syntax error: unexpected token `;'");
	if (check_forbidden_background() == FALSE)
		return ("syntax error: unexpected token `&'");
	if (check_start_pipe() == FALSE)
		return ("syntax error: unexpected token `|'");
	if (check_end_operators() == FALSE)
		return ("syntax error: unexpected end of file");
	if (check_spaces_between_redirections() == FALSE)
		return ("syntax error: unexpected token `>'");
	if (check_spaces_between_heredock() == FALSE)
		return ("syntax error: unexpected token `<'");
	return (NULL);
}
