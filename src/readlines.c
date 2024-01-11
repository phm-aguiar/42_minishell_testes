/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/11 19:28:04 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	token_type(t_minishell *core, int capacity)
{
	int	i;

	i = -1;
	while (++i < capacity)
	{
		if (ft_strcmp(core->input[i].value, "|") == 0)
			core->input[i].type = TOKEN_PIPE;
		else if (ft_strcmp(core->input[i].value, "<") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, ">") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, ">>") == 0)
			core->input[i].type = TOKEN_REDIRECTION;
		else if (ft_strcmp(core->input[i].value, "&") == 0)
			core->input[i].type = TOKEN_BACKGROUND;
		else
			core->input[i].type = TOKEN_WORD;
	}
}

static void	parse_input(char *input, t_minishell *core)
{
	char	**commands;
	int		len;
	int		i;

	i = -1;
	commands = ft_split(input, ' ');
	len = ft_matrixlen(commands);
	while (++i < len)
		core->input[i].value = commands[i];
	core->input[i].value = NULL;
	free(commands);
	token_type(core, len);
}

void	readlines(t_minishell *core)
{
	char	*input;
	int		i;

	using_history();
	while (1)
	{
		input = readline("MiniShell: ");
		add_history(input);
		parse_input(input, core);
		i = -1;
		while (core->input[++i].value)
		{
			printf("value: %s\n", core->input[i].value);
			printf("type: %d\n", core->input[i].type);
		}
		if (ft_strcmp(input, "exit()") == 0)
		{
			free(input);
			break ;
		}
		free(input);
	}
	rl_clear_history();
}
