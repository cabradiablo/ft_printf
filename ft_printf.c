/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:43:21 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/21 14:40:28 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == '\0')
				break ;
			count += ft_typechecker(format[i], ap);
		}
		else
			count += ft_putchar(format[i]);
		++i;
	}
	va_end(ap);
	return (count);
}
int	main(void)
{
	ft_printf("me llamo Ale %d", -25);
	return (0);
}
