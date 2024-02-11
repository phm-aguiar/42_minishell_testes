/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:00 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/11 16:29:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	has_apending(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '>' && str[i + 1] == '>')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	replace_input(void)
{
	char	*str;

	str = get_core()->input;
	str = ft_replace(str, ">>", "£");
	str = ft_replace(str, ">", "¢");
	str = ft_replace(str, "£", " >> ");
	str = ft_replace(str, "<<", "£");
	str = ft_replace(str, "<", "¢");
	str = ft_replace(str, "£", " << ");
	str = ft_replace(str, "¢", " > ");
	str = ft_replace(str, "¢", " < ");
	str = ft_replace(str, "|", "£");
	str = ft_replace(str, "£", " | ");
	str = ft_replace(str, " ", "£");
	printf("str: %s\n", str);
	split_by_spaces(str);
	get_core()->input = str;
}
