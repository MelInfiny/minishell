/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:18:37 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/31 16:46:23 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	lexer_char_error(char content)
{
	ft_printf("error syntaxe unexpected token : `, ");
	if (content)
		ft_printf("%c", content);
	ft_printf("\n");
	return (-1);
}

int	lexer_str_error(char *content)
{
	ft_printf("error syntaxe unexpected token : `, ");
	if (content)
		ft_printf("%s", content);
	ft_printf("\n");
	return (-1);
}
