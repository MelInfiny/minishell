#include "header.h"

static int      ft_cderror(void)
{
        perror("cd");
	return (1);
}

static char	*ft_chr_env(char **env, char *var)
{
	size_t	count;

	count = 0;
	if (!env)
		 return (NULL);
	while (env[count])
	{
		if (ft_findstr(env[count], var))
		{
			return (env[count] + ft_strlen(var) + 1);
		}
		count ++;
	}
	return (NULL);
}

void	ft_replace_varenv(char **env, char *var, char *newvar)
{
	size_t	count;
	char	*tmp;

	count = 0;
	if (!env)
		return ;
	while (env[count])
	{
		if (ft_findstr(env[count], var))
		{
			tmp = ft_strjoin(var, "=");
			free(env[count]);
			env[count] = NULL;
			env[count] = ft_strjoin(tmp, newvar);
			free(tmp);
		}
		count ++;
	}
}

static char	*get_target(t_input *input, char **args, int nb_args)
{
	char	*target;
	
	target = NULL;
	if (nb_args == 1)
		target = ft_chr_env(input->env, "HOME");
	else if (nb_args == 2)
	{
		if (!my_strcmp(args[1], "-"))
			target = ft_chr_env(input->env, "OLDPWD");
		else
			target = args[1];
	}
	else
	{
		ft_cderror();
		return (NULL);
	}
	if (!target && nb_args == 1)
		ft_putstr_fd("cd: HOME not set\n", 2);
	else if (!target)	
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
	return (target);
}

int     ft_cd(t_input *input, char **args, int nb_arg)
{
        char    cdd[PATH_MAX];
	char	*target;

	target = get_target(input, args, nb_arg);
	if (!target)
		return (1);
	getcwd(cdd, PATH_MAX);
	if (chdir(target))
		return (ft_cderror());
	ft_replace_varenv(input->env, "OLDPWD", cdd);
	ft_replace_varenv(input->env, "PWD", getcwd(cdd, PATH_MAX));
        return (0);
}
