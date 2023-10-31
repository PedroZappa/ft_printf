/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:44 by passunca          #+#    #+#             */
/*   Updated: 2023/10/31 11:52:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

static void	ft_puthex(unsigned long hex);
static int	ft_hexlen(unsigned long nb);
static char	*ft_x(t_format p);

// p = parsed
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
	ft_puthex(nb);
	return (len);
}

int	ft_print_x(t_format p, va_list ap)
{
	unsigned int	nb;
	int		len;

	(void)p;
	nb = va_arg(ap, unsigned int);
	if (!nb)
		return (ft_putstrn_fd("(nil)", 1, 5));
	len = (ft_hexlen(nb) + 2);
	ft_putstr_fd(ft_x(p), 1);
	ft_puthex(nb);
	return (len);
}

static void	ft_puthex(unsigned long nb)
{
	if (nb < 0)
		nb *= -1;
	if (nb < 16)
		ft_putchar(HEX_LOWER[nb]);
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
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
