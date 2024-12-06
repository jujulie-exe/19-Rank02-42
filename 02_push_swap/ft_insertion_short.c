
#include "push_swap.h"

int	empty(t_list **head)
{
	if(head == NULL || *head == NULL)
		return (0);
	else
		return (1);
}

int	is_sorted(t_list **head)
{
	t_list	*current;
	t_list	*compare;

	current = *head;
	while (empty(head))
	{
		compare = current;
		while (1)
		{
			if (compare->value > current->value)
				return (0);
			compare = compare->next;
			if (compare == current)
				break ;
		}
		current = current->next;
		if (current == *head)
			break ;
	}
	return (1);
}

t_list	*get_gap_node(t_list **head, int index)
{
	t_list	*current;
	int	i;

	current == *head;
	i = 0;
	if (empty(head) == 0)
		return (NULL);
	while (empty(head) || i > index)
	{
		current = current->next;
		i++;
		if (current == *head)
			break ;
	}
	return (current);

}

void	insertion_short(t_list **head_a, t_list **head_b)
{
	t_list	*min_value;


	while (empty(head_a))
	{
		
		min_value = find_smallest(head_a);
		while ((*head_a)->value != min_value->value)
			ra(head_a);
		pb(head_b, head_a);
	}
	while (empty(head_b))
		pa(head_a, head_b);
}

void 	shell_short(t_list **head_a, t_list **head_b)
{
	int	len_a;
	int	gap;
	int	i;
	t_list	*current;
	t_list	*gap_node;

	len_a = ft_lenstck(*head_a);
	gap = len_a / 2;
	if (!(empty))
		return ;
	while (gap > 0)
	{
		i = 0;
		while (i < len_a - gap)
		{
			current = get_gap_node(head_a, i);
			gap_node = get_gap_node(head_a, i + gap);
			if (current->value > gap_node->value)
			{
				while (*head_a != current)
						ra(head_a);
				pb(head_b, head_a);
				while (*head_a != gap_node)
					ra(head_a);
				pb(head_b, head_a);
				if ((*head_b)->value < (*head_b)->next->value)
					sb(head_b);
				pa(head_a, head_b);
				pa(head_a, head_b);
			}
		i++;
		}
		gap /= 2;
	}
	if ((is_sorted))
		insertion_short(head_a, head_b);


}
