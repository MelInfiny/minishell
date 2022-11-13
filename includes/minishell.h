#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
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

#endif
