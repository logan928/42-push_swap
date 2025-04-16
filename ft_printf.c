/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:12:27 by uwettasi          #+#    #+#             */
/*   Updated: 2025/04/16 15:13:07 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	ft_print_str(char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		length += ft_print_char((int)str[i]);
		i++;
	}
	return (length);
}

static int	ft_print_format(char specifier, va_list *ap)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length += ft_print_char(va_arg(*ap, int));
	else if (specifier == 's')
		length += ft_print_str(va_arg(*ap, char *));
	else if (specifier == '%')
		length += ft_print_char('%');
	else
		length += write(1, &specifier, 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	va_start(ap, format);
	length = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			length += ft_print_format(*format, &ap);
		}
		else
			length += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (length);
}
