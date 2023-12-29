/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/29 10:42:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	readlines(void)
{
	char	*input;

	using_history();
	while (1)
	{
		input = readline("MiniShell: PWD$ ");
		add_history(input);
		if (ft_strcmp(input, "exit()") == 0)
		{
			free(input);
			break ;
		}
		free(input);
	}
	rl_clear_history();
}
