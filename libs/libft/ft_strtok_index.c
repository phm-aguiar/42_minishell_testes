/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:11:40 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 18:26:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*strtok_index(char *str, const char *delim, size_t *index)
{
	size_t	start;
	size_t		end;
	size_t		in_quote;
	char	*token;

	if (str == NULL || *index >= strlen(str))
		return (NULL);
	start = *index;
	end = start;
	in_quote = 0;
	while (str[start] && (strchr(delim, str[start]) || in_quote))
	{
		if (str[start] == '\"' || str[start] == '\'')
			ft_skip_quotes(str, &start);
		else if (!in_quote)
			start++;
		else
			break ;
	}
	end = start;
	while (str[end] && (!strchr(delim, str[end]) || in_quote))
	{
		if (str[end] == '\"' || str[end] == '\'')
			in_quote = !in_quote;
		end++;
	}
	*index = end;
	token = (char *)malloc(end - start + 1);
	if (token == NULL)
		return (NULL);
	strncpy(token, str + start, end - start);
	token[end - start] = '\0';
	return (token);
}
