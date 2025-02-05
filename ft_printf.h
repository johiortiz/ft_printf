/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:11:29 by johyorti          #+#    #+#             */
/*   Updated: 2025/01/20 12:11:31 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nbr);
int	ft_putunbr(unsigned int n);
int	ft_puthexadecimal(unsigned long num, char format);
int	ft_pointerhex(void *ptr);
int	ft_result(va_list args, unsigned char c);
int	ft_printf(char const *format, ...);

#endif