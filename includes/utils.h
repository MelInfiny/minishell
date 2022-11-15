#ifndef UTILS_H
# define UTILS_H

typedef enum {
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
}	e_builtins;

typedef enum {
	ET,
	OU,
	PIPE,
} e_delim;

typedef struct s_quotes {
	int	start;
	int	end;
	int	index;
	bool	pair;
}	t_quote;

typedef struct s_input {
	e_builtins	builtins;
	e_delim		delim;
	char		**env;
	char		*raw;
	char		*line;
}	t_input;

typedef struct s_readline {
	char	*line;
	char	*last;
	char	*buff;
	char	*history[500];
	int		index;
	int		fd_hisotry;
	int		size_history;
}	t_readline;


bool	ft_equalstr(char *str, char *find);
bool	ft_findstr(char *str, const char *find);
void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);
#endif
