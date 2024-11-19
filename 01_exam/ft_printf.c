#include <unistd.h>
#include <stdarg.h>

int ft_putchar(int c)
{
	return write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return write(1, "(null)", 6);
	while (str[i] != '\0')
	{
		ft_putchar((int)str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return write(1, "-2147483648", 11);
	if(n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if(n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

int ft_puthex(unsigned int n)
{
	int	count;
	char	*symb;

	count = 0;
	symb = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += write(1, &symb[n % 16], 1);
	return (count);
}

int	ft_frmt(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list ap;
	int	count;

	va_start (ap, frmt);
	count = 0;
	while (*frmt != '\0')
	{
		if(*frmt == '%')
			count += ft_frmt(*(++frmt), ap);
		else
			count += write(1, frmt, 1);
		frmt++;
	}
	va_end(ap);
	return (count);
}
