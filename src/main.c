/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/09 16:07:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	*get_core(void)
{
	static t_minishell	core;

	return (&core);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*core;

	core = get_core();
	(void)argv;
	(void)envp;
	if (argc != 1)
		return (0);
	ft_bzero(core, sizeof(t_minishell));
	readlines();
	return (0);
}
// input_analysis(&core);
// built_in_array(&core);
