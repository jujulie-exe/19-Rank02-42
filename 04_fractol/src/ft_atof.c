
#include "fractol.h"

size_t	skip_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	get_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

double	get_result(int sign, const char *str, size_t *i)
{
	double		result;
	double		fraction;
	double		divisor;

	result = 0.0;
	fraction = 0.0;
	while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		divisor = 10.0;
		(*i)++;
		while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
		{
			fraction += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
		}
	}
	return ((result + fraction) * sign);
}

double	ft_atof(const char *str)
{
	size_t		i;
	double		result;
	int			sign;

	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	result = get_result(sign, str, &i);
	return (result);
}
