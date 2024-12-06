/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:06:05 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/05 15:30:55 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_both_rev(t_list **head_a, t_list **head_b, t_list *cheapest, char a)
{
	if (a == 'r')
	{
		while (*head_a != cheapest->target_node && *head_b != cheapest)
			rr(head_a, head_b);
	}
	if (a == 'v')
	{
		while (*head_a != cheapest->target_node && *head_b != cheapest)
			rrr(head_a, head_b);
	}
	set_index(head_a);
	set_index(head_b);
}

/*void	rev_both(t_list **head_a, t_list **head_b)
{
	while (*head_a != cheapest->tagret_node && *head_b != cheapest)
		rrr(head_a, head_b);
	set_index(head_a);
	set_index(head_b);
}*/

void	end_rot(t_list **head, t_list *top, char n)
{
	if (head == NULL || *head == NULL || top == NULL)
		return ;
	if (*head == (*head)->next)
		return ;
	while (*head != top)
	{
		if (n == 'a')
		{
			if (top->above_median)
				ra(head);
			else 
				rra(head);
		}
		else if (n == 'b')
		{
			if (top->above_median)
				rb(head);
			else
				rrb(head);
		}
	}
}

void	is_in_list(t_list **head, t_list *node)
{
	t_list *current = *head;
	while (1)
	{
		if (current == node)
			write(1, "1\n", 2);
		current = current->next;
		if (current == *head)
		{
			write(1, "0\n", 2);
			break ;
		}
	}
}

int	move(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;

	cheapest = return_cheapest(head_b);
	if (cheapest == NULL)
		return (0);

	if (cheapest->above_median && cheapest->target_node->above_median)
		rot_both_rev(head_a, head_b, cheapest, 'r');
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rot_both_rev(head_a, head_b, cheapest, 'v');
	//is_in_list(head_b, cheapest);
	end_rot(head_a, cheapest->target_node, 'a');
	end_rot(head_b, cheapest, 'b');
	pa(head_a, head_b);
	return (1);
}

void	push_swap(t_list **head_a, t_list **head_b)
{
	int	len_a;
	t_list	*smallest;
	int	len_b;

	len_a = ft_lenstck(*head_a);
	len_b = 0;
	if (len_a == 5)
		return ;
	else
	{
		while (len_a-- > 3)
			pb(head_b, head_a);
	}
	ft_ts(head_a);
	while ((len_b = ft_lenstck(*head_b)) != 0)
	{
		init(head_a, head_b);
		move(head_a, head_b);
	}
	set_index(head_a);
	smallest = find_smallest(head_a);
	if (!(smallest->above_median))
		while (*head_a != smallest)
			ra(head_a);
	else
		while (*head_a != smallest)
			rra(head_a);
}
