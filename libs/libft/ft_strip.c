/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:15:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/09 16:15:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strip(char *str)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (str == NULL || *str == '\0')
		return ;
	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (start < len && ft_isspace(str[start]))
		start++;
	while (end > start && ft_isspace(str[end]))
		end--;
	if (start > 0 || end < len - 1)
		ft_memmove(str, str + start, end - start + 1);
	str[end - start + 1] = '\0';
}
