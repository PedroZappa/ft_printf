/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:35:25 by passunca          #+#    #+#             */
/*   Updated: 2024/02/11 11:59:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long nb, t_format p);
static int	ft_hexlen(unsigned long nb);
static char	*ft_x(t_format p);

int	ft_print_ptr(t_format p, va_list ap)
{
	long	nb;
	int		len;

	(void)p;
	nb = (unsigned long)va_arg(ap, void *);
	if (!nb)
		return (ft_putstrn_fd("(nil)", 1, 5));
	len = (ft_hexlen(nb) + 2);
	ft_putstr_fd(ft_x(p), 1);
	ft_putptr(nb, p);
	return (len);
}

static void	ft_putptr(unsigned long nb, t_format p)
{
	if (nb < 16)
		ft_putchar(HEX_LOWER[nb]);
	if (nb >= 16)
	{
		ft_putptr((nb / 16), p);
		ft_putchar(HEX_LOWER[nb % 16]);
	}
}

static int	ft_hexlen(unsigned long nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 16;
		++len;
	}
	return (len);
}

static char	*ft_x(t_format p)
{
	if (p.specifier == 'X')
		return ("0X");
	return ("0x");
}
