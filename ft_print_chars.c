/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:16:29 by zedr0             #+#    #+#             */
/*   Updated: 2023/10/19 18:32:28 by zedr0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format parsed, va_list ap)
{
	char	c;
	int		len;
	int		n;

	len = 0;
	n = (parsed.width - parsed.precision);
	if (parsed.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	parsed.precision = 0;
	if (!parsed.minus && parsed.zero)
		len += ft_putnchar_fd('0', 1, n);
	else if (!parsed.minus && (parsed.width > parsed.precision))
		len += ft_putnchar_fd(' ', 1, n);
	len += ft_putchar_fd(c, 1);
	if (parsed.minus && (parsed.width - parsed.precision > 0))
		len += ft_putnchar_fd(' ', 1, n);
	return (len);
}

int	ft_print_str(t_format parsed, va_list ap)
{
	char	*str;
	int		len;
	int		n;

	len = 0;
	n = (parsed.width - parsed.precision);
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (parsed.dot || (parsed.precision > (int)ft_strlen(str))
		|| parsed.precision < 0)
		parsed.precision = (int)ft_strlen(str);
	if (!parsed.minus && (parsed.width > parsed.precision) && parsed.zero
		&& (!parsed.dot || parsed.neg_precision))
		len += ft_putnchar_fd('0', 1, n);
	else if (!parsed.minus && ((parsed.width - parsed.precision) > 0))
		len += ft_putnchar_fd(' ', 1, n);
	len += ft_putstrn_fd(str, 1, parsed.precision);
	if (parsed.minus && (parsed.width - parsed.precision > 0))
		len += ft_putnchar_fd(' ', 1, n);
	return (len);
}