
#include "push_swap.h"

void	ft_stack_a(t_list **head_a, char **argv)
{
	int	i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			return ;
		}
		if (*head_a == NULL)
			*head_a = lstnew((int)(n));
		else
			lstadd(head_a, (int)n);
		i++;

	}
	// mettere if per la verifica della stringa isdigit
	
}

void init(t_list **head_a, t_list **head_b)
{

}


