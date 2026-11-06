/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbihti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:04:23 by mbihti            #+#    #+#             */
/*   Updated: 2026/10/26 13:26:09 by mbihti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char type, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_c('%');
	else if (type == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	else if (type == 's')
		count += g_print_str(va_arg(args, const char *), flags);
	else if (type == 'd' || type == 'i')
		count += g_print_int(va_arg(args, int), flags);
	else if (type == 'p')
		count += g_print_ptr(va_arg(args, void *), flags);
	else if (type == 'u')
		count += g_print_unsigned(va_arg(args, unsigned int), flags);
	else if (type == 'x')
		count += g_print_hex(va_arg(args, unsigned long), 0, flags);
	else if (type == 'X')
		count += g_print_hex(va_arg(args, unsigned long), 1, flags);
	return (count);
}

int	ft_parse_flags(const char *str, int i, t_flags *flags)
{
	while (str[++i] && ft_istype(str[i]))
	{
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '-')
			flags->left = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '0')
			flags->zero = 1;
		if (ft_isdigit(str[i]))
			i += ft_width_flag(str, i, flags);
		if (str[i] == '.')
			i += ft_precision_flag(str, i, flags);
		if (ft_isspec(str[i]))
		{
			flags->spec = str[i];
			return (i);
		}
	}
	return (i);
}

int	ft_parse(char *str, va_list args)
{
	int		i;
	int		x;
	int		count;
	t_flags	flags;

	i = -1;
	count = 0;
	while (str[++i])
	{
		flags = ft_flags_init();
		if (str[i] == '%' && str[i + 1])
		{
			x = ft_parse_flags(str, i, &flags);
			if (flags.spec > 0)
				i = x;
			if (str[i] != '\0' && flags.spec > 0 && ft_isspec(str[i]))
				count += ft_print_arg(str[i], args, &flags);
			else if (str[i])
				count += ft_print_c(str[i]);
		}
		else
		{
			if (str[i] == '%' && !str[i + 1])
				return (-1);
			count += ft_print_c(str[i]);
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;

	if (!format || !(*format))
		return (0);
	str = ft_strdup(format);
	if (!str)
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}
