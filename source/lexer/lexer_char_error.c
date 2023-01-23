/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_char_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:18:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/12 11:15:24 by tda-silv         ###   ########.fr       */
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
