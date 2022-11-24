#ifndef UTILS_H
# define UTILS_H

typedef enum {
	WORD,
	SQUOTE,
	DQUOTE,
	DOLLAR,
	PIPE,
	ESPACE,
	DREDIR,
	DRREDIR,
	GREDIR,
	GRREDIR
}	e_type;


typedef struct s_quotes {
	int	start;
	int	end;
	int	index;
	bool	pair;
}	t_quote;

typedef struct s_map {
	int			key;
	char		*content;
	e_type		type;
	struct s_map	*next;
} t_map;

typedef struct s_dup {
	int	fin;
	int	fout;
	int	file;
	e_type	type;
} t_dup;

typedef	struct	s_token {
	int	fin;
	int	fout;
	int	type;
	char	*cmd;
	char	**option;
	char	**args;
} t_token;

typedef struct s_input {
	char		**env;
	char		*raw;
	char		*line;
	int		fdin;
	int		fdout;
	t_map		*lexer;
	t_list		*parser;
}	t_input;

typedef struct s_parser {
	t_list	*cmds;
	t_list	*redir;
} t_parser;

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
void	ft_strisert(char *newline, char *add, size_t len);

void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);
char	**ft_strdjoin(char **strd, char *s);
char	**ft_strsplit(char *s, char c);

// ******************** MAP **************************
t_map	*ft_getmap(t_map *map, int key);
t_map	*ft_mapnew(char *content, e_type type);
t_map	*ft_maplast(t_map *map);
void	ft_addmap(t_map **map, t_map *newmap);
void	ft_mapdelone(t_map *map, void (*del)(void *));
void	ft_mapreplace(t_map **map, t_map *newmap);
void	ft_mapclear(t_map **map, void (*del)(void *));
int		ft_mapsize(t_map *map);
// *****************************************************
// ********************* PARSER ************************

t_list	*ft_newcmd(char **infos);
t_list	*ft_newredir(char **infos);



#endif
