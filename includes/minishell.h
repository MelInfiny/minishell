#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"

typedef struct s_readline {
	char	*buffer;
	char	**history;
	int	fd;	
}	t_readline;

int	ft_prompt(void);

int	redirect(char *file);
#endif
