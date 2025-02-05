/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:11:47 by johyorti          #+#    #+#             */
/*   Updated: 2025/01/20 15:09:10 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadecimal(unsigned long num, char format)
{
	int		i;
	char	*type;

	i = 0;
	if (format == 'x')
		type = "0123456789abcdef";
	else
		type = "0123456789ABCDEF";
	if (num >= 16)
		i += ft_puthexadecimal(num / 16, format);
	i += ft_putchar(type[num % 16]);
	return (i);
}

int	ft_pointerhex(void *ptr)
{
	int	j;

	j = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	j += ft_putstr("0x");
	j += ft_puthexadecimal((unsigned long)ptr, 'x');
	return (j);
}
