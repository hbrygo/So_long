/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:04:52 by hubrygo           #+#    #+#             */
/*   Updated: 2023/05/23 15:01:18 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_put_unsigned_nbr(unsigned int nb, size_t *len)
{
	unsigned int	num;

	if (nb >= 10)
	{
		ft_put_unsigned_nbr(nb / 10, len);
		ft_put_unsigned_nbr(nb % 10, len);
	}
	if (nb < 10)
	{
		num = nb + 48;
		write (1, &num, 1);
		(*len)++;
	}
	return (*len);
}

size_t	ft_putnbr(int nb, size_t *len)
{
	int	num;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*len) += 11;
		return (*len);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		(*len)++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		num = nb + 48;
		write (1, &num, 1);
	}
	return ((*len)++);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_base(unsigned int nb, int i, size_t *len)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, i, len);
		ft_putnbr_base(nb % 16, i, len);
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
