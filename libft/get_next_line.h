/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:48:33 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/31 16:51:31 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t	ft_strlen2(const char *s);
char	*ft_strjoin2(char *s1, const char *s2);
char	*ft_substr2(const char *s, unsigned int start, size_t len);
char	*trim_buff(char **s_save, char *buff, int status);
char	*read_buff(char **s_save, char *line, int fd);
char	*get_next_line(int fd);

#endif
