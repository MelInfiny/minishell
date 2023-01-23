/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_varenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:15:58 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/17 04:16:19 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_replace_varenv(char **env, char *var, char *newvar)
{
	size_t	count;
	size_t	len;
	char	*tmp;

	count = 0;
	len = ft_strlen(var);
	if (!env)
		return ;
	while (env[count])
	{
		if (!ft_strncmp(var, env[count], len) && env[count][len] == '=')
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
