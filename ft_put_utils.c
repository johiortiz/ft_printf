/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:11:20 by johyorti          #+#    #+#             */
/*   Updated: 2025/01/20 18:18:08 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		i;
	char	num;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		i += ft_putunbr(n / 10);
	num = n % 10 + '0';
	i += ft_putchar(num);
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int		i;
	char	num;

	i = 0;
	if (n >= 10)
		i += ft_putnbr(n / 10);
	num = n % 10 + '0';
	i += ft_putchar(num);
	return (i);
}
