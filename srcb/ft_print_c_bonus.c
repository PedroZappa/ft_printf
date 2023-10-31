/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:00 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 22:39:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int ft_putwidth(t_format p, int *len);

int	ft_print_char(t_format p, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (p.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	p.width -= ft_putwidth(p, &len);
	len += ft_putchar_fd(c, 1);
	ft_putwidth(p, &len);
	return (len);
}

int ft_putwidth(t_format p, int *len)
{
	int i;

	i = 0;
	if ((p.width > 1) && !p.minus)
	{
		while (!p.minus && p.width > 1)
		{
			len += ft_putchar_fd(' ', 1);
			--p.width;
			++i;
		}
	}
	return (i);
}
