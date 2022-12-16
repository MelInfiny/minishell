/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 12:59:56 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void     first_check(t_input *input);
static void     change_handler_and_start_execute(t_input *input);
static void     init_struct_sigaction(t_input *input, struct sigaction *ssa);
static void     prompt(t_input *input);

int     g_status;
/*

void	print_type(t_type type)
{
	printf("\n");
	if (type == WORD)
		printf("WORD");
	if (type == DQUOTE)
		printf("DQUOTE");
	if (type == SQUOTE)
		printf("SQUOTE");
	if (type == DOLLAR)
		printf("DOLLAR");
	if (type == ESPACE)
		printf("ESPACE");
	if (type == PIPE)
		printf("PIPELINE");
	if (type == GREDIR)
		printf("GREDIR");
	if (type == DREDIR)
		printf("DREDIR");
	if (type == GRREDIR)
		printf("GRREDIR");
	if (type == DRREDIR)
		printf("DRREDIR");
}

void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		print_type(tmp->type);
		printf(" %d: ", tmp->key);
		printf(" len = %ld: ", ft_strlen(tmp->content));
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_ast(t_list *ast)
{
	t_list	*tmp;
	t_list	*r;
	t_redir	*redir;
	t_node	*node;

	tmp = ast;
	if (!ast)
		return ;
	while (tmp)
	{
		printf("NEW COMMAND\n");
		node = tmp->content;
		r = node->redir;
		while (r)
		{
			redir = r->content;
			printf("redir : %d ", redir->type);
			printf("%s\n", redir->file);
			r = r->next;
		}
		for (size_t i = 0; node->args[i]; i++)
				printf("%ld: %s\n", i, node->args[i]);
		tmp = tmp->next;
	}
}

void	test_lexer(t_input *input)
{
	lexer(input, input->raw);
	check_syntax(input);
	check_expand(input);
	print_map(input->lexer);
}

void	test_ast(t_input *input)
{
	parser(input);
	print_ast(input->ast);
}

*/
int     main(int argc, char **argv, char **env)
{
		t_input                         input;
		struct sigaction        ssa;

		(void) argc;
		(void) argv;
		g_status = 0;
		init_struct_sigaction(&input, &ssa);
		if (copy_env(env, &input) || copy_env_in_export(&input) || shlvl(&input))
				ms_exit(&input, 1);
		prompt(&input);
		free_all(&input);
		return (0);
}

/* ************************************************************************** */
/*                                                                                                                                                        */
/*   Terminos et les focntins tc[...] change le comportement du terminal.         */
/*   Le flag ECHOCTL est activé pour les nouvelles règles du terminal,            */
/*   il permet ne pas afficher les signaux comme "^C".                                            */
/*                                                                                                                                                        */
/* ************************************************************************** */
static void     prompt(t_input *input)
{
		struct termios          termios_new;

		tcgetattr(0, &termios_new);
		termios_new.c_lflag &= ~ECHOCTL;
		tcsetattr(0, 0, &termios_new);
		ft_putstr_fd("\n\033[36mThe default interactive shell is now", 2);
		ft_putstr_fd(" \033[36;01mminishell.\033[00m\n", 2);
		while (1)
		{
				init_input(input, readline("$> "));
				if (!input->raw)
						ms_exit(input, 0);
				if (ft_strlen(input->raw) > 0)
				{
						//test_lexer(input);
						//test_ast(input);
						first_check(input);
						add_history(input->raw);
				}
				free_input(input);
		}
}

void     first_check(t_input *input)
{
		if (!lexer(input, input->raw))
		{
			g_status = 2;
			return ;
		}
		if (!check_syntax(input))
		{
			g_status = 2;
			return ;
		}
		
		if (!check_pipes(input))
		{
			g_status = 0;
			return ;
		}
		check_expand(input);
		parser(input);
		change_handler_and_start_execute(input);
}

/* ************************************************************************** */
/*																			  */
/*   Passe le gestionnaire de signaux en non interactif avce handler_off.     */
/*   En mode non interactif, aucun signal n'est interprété.	    			  */
/*   Puis, repasse en mode interactif aprés l'éxecution.					  */
/*																			  */
/* ************************************************************************** */
static void	change_handler_and_start_execute(t_input *input)
{
	input->ssa->sa_handler = &handler_off;
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
	execute(input);
	input->ssa->sa_handler = &handler_on;
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
}

static void	init_struct_sigaction(t_input *input, struct sigaction *ssa)
{
	input->env = NULL;
	input->export = NULL;
	input->ssa = ssa;
	input->ssa->sa_handler = &handler_on;
	input->ssa->sa_flags = SA_RESTART;
	sigemptyset(&input->ssa->sa_mask);
	sigaction(SIGINT, input->ssa, 0);
	sigaction(SIGQUIT, input->ssa, 0);
}
