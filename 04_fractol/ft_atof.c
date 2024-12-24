#include <limits.h>
#include <stdlib.h>
#include <stdio.h> // Solo per debug, rimuovere se non necessario.
#include <ctype.h>
#include <float.h> // Per valori massimi e minimi di double.

size_t	skip_whitespace(const char *str)
{
	size_t	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	get_sign(const char *str, size_t *i)
{
	int	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

double	ft_atof(const char *str)
{
	size_t		i;
	double		result;
	double		fraction;
	int			sign;

	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	result = 0.0;
	fraction = 0.0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		double divisor = 10.0;
		i++;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			fraction += (str[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
	}
	return (result + fraction) * sign;
}
