/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:10:44 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/11 23:28:13 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_save[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (s_save[fd])
	{
		if (s_save[fd][0])
		{
			line = trim_buff(&s_save[fd], s_save[fd], 1);
			if (line)
				return (line);
			line = ft_strjoin2(line, s_save[fd]);
		}
		free(s_save[fd]);
		s_save[fd] = NULL;
	}
	return (read_buff(&s_save[fd], line, fd));
}

char	*trim_buff(char **s_save, char *buff, int status)
{
	size_t	count;
	size_t	size;
	char	*tmp;

	if (!s_save || !buff)
		return (NULL);
	count = 0;
	size = ft_strlen2(buff);
	while (buff[count])
	{
		if (buff[count] == '\n')
		{
			*s_save = ft_substr2(buff, count + 1, size);
			tmp = ft_substr2(buff, 0, count + 1);
			if (status)
				free(buff);
			return (tmp);
		}
		count ++;
	}
	return (NULL);
}

char	*read_buff(char **save, char *line, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	long int	ft_read;

	buff[0] = '\0';
	ft_read = read(fd, buff, BUFFER_SIZE - ft_strlen2(line));
	while (ft_read > 0)
	{
		buff[ft_read] = '\0';
		tmp = trim_buff(save, buff, 0);
		if (tmp != NULL)
		{
			line = ft_strjoin2(line, tmp);
			free(tmp);
			return (line);
		}
		line = ft_strjoin2(line, buff);
		ft_read = read(fd, buff, BUFFER_SIZE);
	}
	if (ft_read == 0 && line)
		return (line);
	else if (line)
		free(line);
	return (NULL);
}
