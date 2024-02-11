/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/11 16:20:07 by phenriq2         ###   ########.fr       */
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



void	split_by_spaces(char *str)
{
	t_splited	*splited;
	char		*token;

	splited = NULL;
	token = ft_strtok(str, "£");
	while (token)
	{
		splited_add_back(&splited, new_node(token));
		token = ft_strtok(NULL, "£");
	}
	get_core()->splited_input = splited;
	print_splited(get_core()->splited_input);
}
