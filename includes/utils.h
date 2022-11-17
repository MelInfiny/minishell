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

typedef struct s_map {
	int		key;
	void		*content;
	struct s_map	*next;
} t_map;

typedef struct s_input {
	e_builtins	builtins;
	e_delim		delim;
	char		**env;
	char		*raw;
	char		*line;
	t_map		*squotes;
	t_map		*dquotes;
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
void	ft_strisert(char *newline, char *add, size_t len);

void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);

t_map	*getmap(t_map *map, int key);
t_map	*ft_mapnew(void *content);
t_map	*ft_maplast(t_map *map);
void	ft_addmap(t_map **map, t_map *newmap);
void	ft_mapdelone(t_map *map, void (*del)(void *));
void	ft_mapclear(t_map **map, void (*del)(void *));
int	ft_mapsize(t_map *map);

#endif
