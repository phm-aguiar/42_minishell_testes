/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 19:56:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_splited	*new_node(char *str)
{
	t_splited	*new;

	new = malloc(sizeof(t_splited));
	if (!new)
		return (NULL);
	ft_strip(str);
	new->splited = ft_strdup(str);
	new->next = NULL;
	garbage_add(new);
	garbage_add(new->splited);
	free(str);
	return (new);
}

void	splited_add_back(t_splited **splited, t_splited *new)
{
	t_splited	*last;

	if (!*splited)
	{
		*splited = new;
		return ;
	}
	last = *splited;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	print_splited(t_splited *splited)
{
	while (splited)
	{
		printf("%s\n", splited->splited);
		splited = splited->next;
	}
}

void	skip_quotes(char *str, int *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
}

void	split_by_spaces(void)
{
	t_token_process	var;
	char			*str;

	str = get_core()->input;
	ft_bzero(&var, sizeof(t_token_process));
	while (str[var.i])
	{
		if (str[var.i] == '\'' || str[var.i] == '\"')
			skip_quotes(str, &var.i);
		if (ft_isspace(str[var.i]))
		{
			splited_add_back(&var.splited, new_node(ft_substr(str, var.start,
						var.i - var.start)));
			while (ft_isspace(str[var.i]))
				var.i++;
			var.start = var.i;
		}
		var.i++;
	}
	splited_add_back(&var.splited, new_node(ft_substr(str, var.start, var.i
				- var.start)));
	get_core()->splited_input = var.splited;
}
