/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:08:39 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/05 17:23:02 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sorted(t_list **head)
{
	t_list	*current;

	if (head == NULL || *head == NULL)
		return (1);
	current = *head;
	
	while (1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		if (current == (*head)->prev)
			break ;
	}
	
	return (1);

}

int ft_check_double(t_list **head, int nbr)
{
	t_list	*current;

	if (head == NULL || *head == NULL)
		return (0);
	current = *head;
	if (!(*head == (*head)->next))
	{
		while (1)
		{
			if (nbr == current->value)
				return (1);
			current = current->next;
			if (current == *head)
				break ;
		}
	}
	return (0);

}

void	ft_stack_init(t_list **head_a, char **argv, bool control)
{
	int			i;
	long long	n;

	i = 0;
	while (argv[i])
	{
		if ((ft_istrdigit(argv[i])))
			exit_and_free(head_a, argv, control);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_and_free(head_a, argv, control);
		if (ft_check_double(head_a, n) == 1)
			exit_and_free(head_a, argv, control);
		if (*head_a == NULL)
			*head_a = lstnew((int)(n));
		else
			lstadd(head_a, (int)n);
		i++;
	}
}

void	init(t_list **head_a, t_list **head_b)
{
	set_index(head_a);
	set_index(head_b);
	set_target(head_a, head_b);
	set_price(head_a, head_b);
	set_cheapest(head_b);
}
