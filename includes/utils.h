#ifndef UTILS_H
# define UTILS_H

typedef struct s_readline {
	char	*line;
	char	*last;
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
