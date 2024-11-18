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

void	ft_intr(char *s1, char *s2)
{
	int 	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		y = 0;
		while (s2[y] != '\0')
		{
			if (s1[i] == s2[y])
			{
				if ((ft_strchrdup(s1, s1[i], i) == 1))
				{
					write(1, &s1[i], 1);
					break;
				}
			}
			y++;
		}
		i++;
	}
}

int main(int argv, char **argc)
{
	if(argv == 3)
		ft_intr(argc[1], argc[2]);
	write(1, "\n", 1);
	return (0);
}
