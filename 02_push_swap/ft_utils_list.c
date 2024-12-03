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

t_list	*find_last_node(t_list **head)
{
	t_list last_node;
	last_node->(*head)->prev;
	return (last_node);
}

t_list	*find_smallest(t_list **head)
{
	long	min;
	t_list	*current;
	t_list	*smallest_node;

	if (head == NULL || *head == NULL)
		return (NULL);
	min = LONG_MAX;
	current = *head;
	smallest_node = NULL;
	while ((1))
	{
		if (current->value < min)
		{
			min = current->value;
			smallest_node = current;
		}
		current = current->next;
		if (current == *head)
			break ;
	}
	return (smallest_node);
}

t_list *return_chepest(t_list **head)
{
	t_list *current;

	if (head == NULL || *head == NULL)
		return ;
	current = (*head)->next;
	while ((1))
	{
		if (current->cheapest)
			return (current);
		if (current == *head)
			break ;
		current = current->next;
	}
	return (NULL);
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

