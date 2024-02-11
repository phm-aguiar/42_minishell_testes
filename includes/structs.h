/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/10 16:40:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
# define END_FILE "syntax error: unexpected end of file"
# define FORBIDDEN_AND "syntax error: unexpected token `&&'"
# define FORBIDDEN_OR "syntax error: unexpected token `||'"
# define FORBIDDEN_SEMICOLON "syntax error: unexpected token `;'"
# define FORBIDDEN_BACKGROUND "syntax error: unexpected token `&'"
# define FORBIDDEN_PIPE "syntax error: unexpected token `|'"
# define FORBIDDEN_REDIR "syntax error: unexpected token `>'"
# define FORBIDDEN_REDIR_REVERSE "syntax error: unexpected token `<'"

typedef struct s_token			t_token;
typedef struct s_minishell		t_minishell;
typedef struct s_splited		t_splited;
typedef struct s_token_process	t_token_process;

typedef struct s_token_process
{
	t_splited					*splited;
	char						*tmp;
	int							start;
	int							i;
	char						*str;

	t_splited					*tmp_splited;
}								t_token_process;

typedef enum e_bool
{
	FALSE,
	TRUE
}								t_bool;

typedef enum e_tkn_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT,
	TOKEN_REDIRECT_REVERSE,
	TOKEN_APPEND,
	TOKEN_HERE_DOC,
}								t_tkn_type;
typedef struct s_token
{
	char						*value;
	t_tkn_type					type;
	t_token						*next;
	t_token						*prev;

}								t_token;

typedef struct s_splited
{
	char						*splited;
	t_splited					*next;
}								t_splited;

typedef struct s_minishell
{
	t_token						*token;
	t_splited					*splited_input;
	char						*input;
	t_list						*garbage_collector;
	int							exit_status;
}								t_minishell;

#endif
