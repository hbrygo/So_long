/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:01:12 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/19 13:38:33 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_putchar(char c);
size_t	ft_put_unsigned_nbr(unsigned int nb, size_t *len);
size_t	ft_putnbr(int nb, size_t *len);
size_t	ft_putstr(char *str);
size_t	ft_putnbr_base(unsigned int nb, int i, size_t *len);
size_t	ft_put_unsigned_nbr_base(unsigned long long int nb, int i, size_t *len);
int		ft_hub(char c, va_list lst, size_t i);
char	ft_is_in(char c);
int		ft_printf(const char *str, ...);

#endif