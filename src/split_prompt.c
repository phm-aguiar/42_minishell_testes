/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:00 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 21:12:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_splited	*divide_by_append(char *text, t_splited *splited)
{
	t_splited	*result;
	t_splited	*next;
	char		*str;
	int			i;
	int			start;

	result = NULL;
	i = -1;
	start = 0;
	next = splited->next;
	while (text[++i] && text[i + 1])
	{
		if (text[i] == '\'' || text[i] == '\"')
			skip_quotes(text, &i);
		if (text[i] == '>' && text[i + 1] == '>')
		{
			str = ft_substr(text, start, i - start);
			splited_add_back(&result, new_node(str));
			str = ft_strdup(">>");
			splited_add_back(&result, new_node(str));
			start = i + 2;
		}
	}
	str = ft_substr(text, start, i - start + 1);
	splited_add_back(&result, new_node(str));
	splited_add_back(&result, next);
	print_splited(result);
	return (result);
}

void	split_input(void)
{
	char		*str;
	t_splited	*tmp;
	t_splited	*head;
	int			ignore;

	tmp = get_core()->splited_input;
	head = tmp;
	while (tmp)
	{
		str = tmp->splited;
		ignore = (str[0] == '\'' || str[0] == '\"' || !ft_strcmp(str, ">>")
				|| !ft_strcmp(str, "<<") || !ft_strcmp(str, "|")
				|| !ft_strcmp(str, ">") || !ft_strcmp(str, "<"));
		if (!ignore)
		{
			tmp = divide_by_append(str, tmp);
		}
		tmp = tmp->next;
	}
	get_core()->splited_input = head;
	// print_splited(get_core()->splited_input);
}
