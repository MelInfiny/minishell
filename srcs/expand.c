#include "minishell.h"

char    *find_in_env(char **env, char *var)
{
        int             count;

        count = 0;
        while (env[count])
        {
                if (ft_findstr(env[count], var))
                        return (ft_substr(env[count], ft_strlen(var) + 1, ft_strlen(env[count])));
                count ++;
        }
        return (ft_strdup(""));
}

char	*expand_dollar(t_input *input, t_map **map)
{
	t_map	*tmp;

	tmp = (*map)->next;
	if (tmp)
	{
		if (tmp->type == WORD && ft_strlen(tmp->content) > 0)
			return (find_in_env(input->env, tmp->content));
		if (is_break(tmp->type))
			return (ft_strjoin("$", tmp->content));
	}
	return (ft_strdup("$"));
}
