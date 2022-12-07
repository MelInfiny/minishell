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


typedef struct s_map {
	int			key;
	char		*content;
	e_type		type;
	struct s_map	*next;
} t_map;

typedef struct s_redir {
	int	type;
	char	*file;
} t_redir;

typedef struct s_node {
	char	**args;
	t_list	*redir;
} t_node;

typedef struct s_input {
	char		**env;
	char		**paths;
	char		*raw;
	char		*line;
	int		fdin;
	int		fdout;
	t_map		*lexer;
	t_map		*parser;
	t_list		*ast;
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


// ****************** STR ET STRD ********************
void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);
char	**ft_strdjoin(char **strd, char *s);
char	**ft_strsplit(char *s, char c);

char	*ft_streplace(char *s, char *newstr);
bool	ft_findstr(char *str, const char *find);

// ******************** MAP **************************

t_map	*ft_mapnew(char *content, e_type type);
t_map	*ft_maplast(t_map *map);
void	ft_addmap(t_map **map, t_map *newmap);
void	ft_mapdelone(t_map *map, void (*del)(void *));
void	ft_mapreplace(t_map **map, t_map *newmap);
void	ft_mapclear(t_map **map, void (*del)(void *));

#endif
