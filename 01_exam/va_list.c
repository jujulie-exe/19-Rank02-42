int	ft_frmt(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (c == 'd')
		count += ft_putnbr(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list		ap;
	int		count;

	va_start (ap, frmt);
	count = 0;
	while (*frmt != '\0')
	{
		if (*frmt == '%')
			count += ft_frmt(*(++frmt), ap);
		else 
			count += write(1, frmt, 1);
		frmt++;
	}
	va_end(ap);
	return (count);
}
