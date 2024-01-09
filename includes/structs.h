/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:06 by phenriq2          #+#    #+#             */
/*   Updated: 2024/01/09 13:56:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

/**
 * @brief Estrutura que representa um comando

 * @param executable Nome do executável
 * @param arguments Argumentos do comando
 * @param background Flag que indica se o comando deve
 *  executado em background
*/
typedef struct s_command
{
	char				*executable;
	char				**arguments;
	int					background;
}						t_command;

/**
 * @brief Estrutura que representa uma pipeline

 * @param commands Lista de comandos
 * @param num_commands Número de comandos na pipeline
*/

typedef struct s_pipeline
{
	t_command			**commands;
	int					num_commands;
}						t_pipeline;

/**
 * @brief Estrutura que representa um redirecionamento

 * @param file Nome do arquivo para redirecionamento
 * @param type Tipo de redirecionamento (entrada/saída)
*/

typedef struct s_redirection
{
	char				*file;
	int					type;
}						t_redirection;

/**
 * @brief Estrutura que representa um job

 * @param pipeline Sequência de comandos
 * @param input Redirecionamento de entrada
 * @param output Redirecionamento de saída
*/

typedef struct s_job
{
	t_pipeline			*pipeline;
	t_redirection		*input;
	t_redirection		*output;
}						t_job;

/**
 * @brief Estrutura que representa um ambiente

 * @param variables Lista de variáveis de ambiente
 * @param size Número de variáveis de ambiente
 * @param capacity Capacidade máxima da lista de variáveis
*/

typedef struct s_environment
{
	char				**variables;
	int					size;
	int					capacity;
}						t_environment;

/**
 * @brief Estrutura que representa um processo

 * @param pid PID do processo
 * @param status Status do processo
*/

typedef struct s_process
{
	pid_t				pid;
	int					status;
}						t_process;

/**
 * @brief Estrutura que contem o signal
 * @param action Ação a ser executada
 */

typedef struct s_signal_handler
{
	struct sigaction	action;
}						t_signal_handler;

typedef struct s_minishell
{
	t_environment		*env;
	t_command			*command;
	t_pipeline			*pipeline;
	t_redirection		*redirection;
	t_job				*job;
	t_process			*process;
	t_signal_handler	*signal_handler;
}						t_minishell;

#endif
