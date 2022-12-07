#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "utils.h"

// ****************** BUILTINS ********************

int	redirect(char *file);
int	ft_export(char *var, char ***env);
int	ft_unset(const char *var, char ***env);
int	ft_echo(const char *str, int status);
int	ft_exit(char ***env);
int	ft_env(char **env);
int	ft_cd(const char *path);
int	ft_pwd(void);

// ****************** READLINE ********************
void	init_readline(t_readline *prompt);
int		ft_readline(t_readline *prompt);
int		get_line(t_readline *prompt);

// ****************** HISTORY *********************
void	load_history(t_readline *prompt);
void	reverse_history(t_readline *prompt);
int		ft_add_history(t_readline *prompt);
int		last_history(t_readline *prompt);

// ******************* LEXER *********************
void	init_input(t_input *input, char *line, char **env);
void	ft_lexer(t_input *input, char *line);
void	ft_parser(t_input *input);
void	check_syntax(t_input *input);
void	check_expand(t_input *input);
int	is_break(e_type type);
char	*expand_dollar(t_input *input, t_map **map);

// ******************** EXEC ********************
void	ft_pipe(t_input *input);
int	ft_redirect(t_input *input, t_node *node);
char	**ft_path(char **env);

// **************** ERROR ************************
void	free_input(t_input *input);
void	ft_freenode(void *node);
int	ft_cmd_error(t_input *input, t_list *cmd, char *message);
#endif
