/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:28 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/23 13:21:17 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	multiple_option(char **argv);
static int	option_n(char *str);
static void	print_argv(char **argv, int i);

int	ms_echo(char **argv)
{
	int	i;

	if (!argv || !*argv || !**argv)
		return (1);
	if (argv[1])
	{
		i = multiple_option(argv);
		if (i > 1)
		{
			if (argv[i])
				print_argv(argv, i);
		}
		else
		{
			print_argv(argv, i);
			if (write(1, "\n", 1) < 0)
				perror("echo: write error");
		}
	}
	else
	{
		dprintf(2, "coucou\n");
		if (write(1, "\n", 1) < 0)
			perror("echo: write error");
	}
	return (0);
}

static int	multiple_option(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!option_n(argv[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	option_n(char *str)
{
	int	i;

	i = 1;
	if (str && *str && *str == '-')
	{
		if (*(str + 1))
		{
			while (str[i])
			{
				if (str[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

static void	print_argv(char **argv, int i)
{
	while (argv[i])
	{
		if (ft_printf("%s", argv[i++]) == 0)
		{
			perror("echo: write error");
			break;
		}
		if (argv[i])
			ft_printf(" ");
	}
}
