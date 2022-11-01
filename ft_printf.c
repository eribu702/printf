/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:18:38 by aroberts          #+#    #+#             */
/*   Updated: 2022/11/01 17:20:01 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
	return (1);
}

int	ft_flag(va_list	args, const char str)
{
	int		len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0' && str[i] != '\"')
	{
		if (str[i] == '%')
			len += ft_flag(args, str[i + 1]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char	*str;

	str = "Hello World";
	printf("%s\n", str);
	return (0);
}

%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/