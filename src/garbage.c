/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:23:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 09:03:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	garbage_add(void *ptr)
{
	t_list	*gc;

	gc = malloc(sizeof(t_list));
	if (!gc)
		return ;
	gc->value = ptr;
	gc->next = get_core()->garbage_collector;
	get_core()->garbage_collector = gc;
}

void	clear_garbage(void)
{
	t_list	*gc;
	t_list	*next;

	gc = get_core()->garbage_collector;
	while (gc)
	{
		next = gc->next;
		free(gc->value);
		free(gc);
		gc = next;
	}
	get_core()->garbage_collector = NULL;
}
