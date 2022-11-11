#include <stdio.h>
#include <minishell.h>

void	test_cd(int ac, char **argv)
{
	(void) ac;
	char	cw[256];

	printf("%d", ft_cd(argv[1]));
	if (getcwd(cw, sizeof(cw)) == NULL)
		printf("Cannot change directory\n");
	else
		printf("new directory is %s\n", cw);
}

void	test_echo(int ac, char **argv)
{
	(void) ac;
	printf("\n\nTEST SANS OPTION\n\n");
	ft_echo(argv[1], 0);
	printf("\n\nTEST AVEC OPTION\n\n");
	ft_echo(argv[1], 1);
}

void	test_pwd(void)
{
	ft_pwd();
}

int	main(int ac, char **argv, char **env)
{
	(void) ac;
	(void) argv;
	char	**myenv = ft_strdcpy(env);

	ft_export(argv[1], &myenv);
	ft_unset(argv[2], &myenv);
	ft_env(myenv);
	free(myenv);
}
