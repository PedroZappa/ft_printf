/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:16:29 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 17:44:21 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format parsed, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (parsed.specifier == 'c')
		c = va_arg(ap, int);
	else 
		c = '%';
	parsed.precision = 0;
	if (!parsed.minus && parsed.zero)
		len += ft_putnchar_fd('0', 1, (parsed.width - parsed.precision));
	else if (!parsed.minus && (parsed.width > parsed.precision))
		len += ft_putnchar_fd(' ', 1, (parsed.width - parsed.precision));
	len += ft_putchar_fd(c, 1);
	if (parsed.minus && (parsed.width - parsed.precision > 0))
		len += ft_putnchar_fd(' ', 1, (parsed.width - parsed.precision));
	return (len);
}
