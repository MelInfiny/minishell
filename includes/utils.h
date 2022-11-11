#ifndef UTILS_H
# define UTILS_H

typedef struct s_readline {
	char	*buffer;
	char	**history;
	int	fd;	
}	t_readline;

void	ft_strdfree(char **strd);
size_t	ft_strdlen(char **strd);
char	**ft_strdcpy(char **strd);
#endif
