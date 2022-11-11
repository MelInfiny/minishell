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

typedef struct s_readline {
	char	*buffer;
	char	**history;
	int	fd;	
}	t_readline;

int	ft_prompt(void);

int	redirect(char *file);
int	ft_export(char *var, char ***env);
int	ft_unset(const char *var, char ***env);
int	ft_echo(const char *str, int status);
int	ft_env(char **env);
int	ft_cd(const char *path);
int	ft_pwd(void);

void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);
#endif
