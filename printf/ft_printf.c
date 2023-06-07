/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:45:23 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/07 16:45:44 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_unsigned_nbr_base(unsigned long long int nb, int i, size_t *len)
{
	if (nb >= 16)
	{
		ft_put_unsigned_nbr_base(nb / 16, i, len);
		ft_put_unsigned_nbr_base(nb % 16, i, len);
	}
	if (nb < 16 && i == 1)
	{
		*len += 1;
		ft_putchar("0123456789abcdef"[nb]);
	}
	if (nb < 16 && i == 2)
	{
		*len += 1;
		ft_putchar("0123456789ABCDEF"[nb]);
	}
	return (*len);
}

int	ft_hub(char c, va_list lst, size_t i)
{
	if (c == 'c')
		i += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		i += ft_putstr(va_arg(lst, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(lst, int), &i);
	else if (c == 'u')
		ft_put_unsigned_nbr(va_arg(lst, unsigned int), &i);
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		ft_put_unsigned_nbr_base(va_arg(lst, unsigned long long int), 1, &i);
	}
	else if (c == 'x')
		ft_putnbr_base(va_arg(lst, unsigned int), 1, &i);
	else if (c == 'X')
		ft_putnbr_base(va_arg(lst, unsigned int), 2, &i);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

char	ft_is_in(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_is_in(str[i + 1]) == 1)
		{
			len = ft_hub(str[i + 1], lst, len);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
