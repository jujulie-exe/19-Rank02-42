#include "push_swap.h"

int	ft_lenstck(t_list *head)
{
	int	len;
	t_list	*current;

	len = 0;
	if (head == NULL)
		return (len);
	current = head;
	if (current->next == head)
		return (1);
	while (1)
	{
		current = current->next;
		len++;
		if (current == head)
			break ;
	}
	return (len);
}

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

