/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:55:34 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 14:55:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnspn(const char *s, const char *accept, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && i < n)
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				break ;
			j++;
		}
		if (!accept[j])
			return (i);
		i++;
	}
	return (i);
}
