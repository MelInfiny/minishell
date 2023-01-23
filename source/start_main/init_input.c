/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:52 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/10 21:57:57 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_input(t_input *input, char *line)
{
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->ast = NULL;
	input->pids = NULL;
	input->fdin = 0;
	input->fdout = 1;
}
