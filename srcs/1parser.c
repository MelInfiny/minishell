#include "minishell.h"

void	lexer_str_error(t_map **map, char *message, char *content)
{
	printf("%s", message);
	if (content)
		printf("%s", content);
	printf("\n");
	ft_mapclear(map, free);
	exit(0);
}

void	lexer_char_error(t_map **map, char *message, char content)
{
	printf("%s", message);
	if (content)
		printf("%c", content);
	printf("\n");
	ft_mapclear(map, free);
	exit(0);
}

int	is_break(e_type type)
{
	if (type == PIPE || type == GREDIR || type == GRREDIR || type == DREDIR || type == DRREDIR)
		return (1);
	return (0);
}

void	check_syntax(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (tmp->next)
			{
				if (tmp->next->type != WORD)
					lexer_str_error(map, "error : unexpeted token : ` ", tmp->next->content);
			}
			else
					lexer_str_error(map, "error : unexpeted token : << newline >>", NULL);
		}
		tmp = tmp->next;
	}
}

