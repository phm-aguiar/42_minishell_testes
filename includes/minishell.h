/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2024/02/11 13:28:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "structs.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

void		readlines(void);
t_minishell	*get_core(void);
t_bool		verify_close_quotes(void);
char		*verify_input(void);

// prompt_check.c
t_bool		check_close_quotes(void);
t_bool		check_forbidden_and(void);
t_bool		check_forbidden_or(void);
t_bool		check_forbidden_semicolon(void);
t_bool		check_forbidden_background(void);

// prompt_handling.c

char		*check_input_error(void);
t_bool		check_spaces_between_heredock(void);
t_bool		check_spaces_between_redirections(void);
t_bool		check_end_operators(void);
t_bool		check_start_pipe(void);

// garbage_collector.c

void		garbage_add(void *ptr);
void		clear_garbage(void);

// error.c

void		set_exit_status(char *error_msg);

// input.c

void		split_by_spaces(char *str);
void		skip_quotes(char *str, int *i);
void		print_splited(t_splited *splited);
void		splited_add_back(t_splited **splited, t_splited *new);
t_splited	*new_node(char *str);
void		replace_input(void);
#endif
