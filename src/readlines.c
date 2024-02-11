/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:18:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 20:53:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	readlines(void)
{
	char	*error_msg;

	using_history();
	while (1)
	{
		get_core()->input = readline("testando: ");
		add_history(get_core()->input);
		ft_strip(get_core()->input);
		garbage_add(get_core()->input);
		error_msg = check_input_error();
		if (error_msg)
		{
			set_exit_status(error_msg);
			continue ;
		}
		split_by_spaces();
		split_input();
		if (ft_strcmp(get_core()->input, "exit") == 0)
		{
			clear_garbage();
			break ;
		}
		clear_garbage();
	}
	rl_clear_history();
}
