#include <unistd.h>

int	ft_strchrdup(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	while (s1[i] != '\0')
	{
		if ((ft_strchrdup(s1, s1[i], i) == 1))
			write(1, &s1[i], 1);
		i++;
	}
	len = i;
	i = 0;
	while (s2[i] != '\0')
	{
		if ((ft_strchrdup(s2, s2[i], i) == 1))
		{
			if ((ft_strchrdup(s1, s2[i], len) == 1))
				write(1, &s2[i], 1);
		}
		i++;
	}
}

int main(int argv, char **argc)
{
	if (argv == 3)
		ft_union(argc[1], argc[2]);
	write(1, "\n", 1);
}
