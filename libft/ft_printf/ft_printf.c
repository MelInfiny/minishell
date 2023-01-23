/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:02 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/23 13:20:36 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	ellipse;
	t_data	data;

	ft_datazero(&data);
	if (s)
	{
		va_start(ellipse, s);
		while (ft_putstr_printf(s, &data))
			if (ft_convchr(s, &data))
				ft_convselect(s, &data, &ellipse);
		va_end(ellipse);
	}
	else
		return (-1);
	return (data.nbr_return);
}
/*
int	main()
{
	char			*s = "%%Testé par %d mes soins.\n";
	int				d = 2147483647;
	int				dd = -2147483648;
	void			*p = (long long int *)-9223372036854775807;
	void			*pp = (long long int*)9223372036854775807;
	unsigned int	u = 4294967295;

	int				i;
	int				j;

	i = ft_printf("%%Testé par %d mes soin%c.", 12, 'S');
	i += ft_printf("\n%s%p\n%p\n%d\n%d\n%u", s, p, pp, d, dd, u);
	i += ft_printf("\n%x\n%x\n%X\n%i\n", d, dd, d, u);
	write(1, "---\n", 4);
	j = printf("%%Testé par %d mes soin%c.", 12, 'S');
	j += printf("\n%s%p\n%p\n%d\n%d\n%u", s, p, pp, d, dd, u);
	j += printf("\n%x\n%x\n%X\n%i\n", d, dd, d, u);

	char *sss; 
//	i = ft_printf(NULL);
//	j = printf(NULL);

	printf("\n\n->i = %d\n--j = %d\n", i, j);
	ft_printf("\n->i = %d\n--j = %d\n", i, j);

	return (0);
}
*/
