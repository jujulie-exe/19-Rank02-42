/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:45:22 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 10:59:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determinite_case(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;
	if (a > b && a > c)
		return (1);
	else if (c < b && c < a)
		return (2);
	else if (b > a && b > c)
		return (3);
	else if (b < c && b < a)
		return (4);
	return (0);
}

void	ft_ts(t_list **head)
{
	int	case_id;

	case_id = determinite_case(head);
	if (case_id == 1)
	{
		ra(head);
		if ((*head)->value > (*head)->next->value)
			sa(head);
	}
	else if (case_id == 2)
		rra(head);
	else if (case_id == 3)
	{
		sa(head);
		ra(head);
	}
	else if (case_id == 4)
	{
		if ((*head)->value < ((*head)->next->next->value))
			sa(head);
		else
			ra(head);
	}
}

void	ft_two_short(t_list **head)
{
	int	a;
	int	b;

	a = (*head)->value;
	b = (*head)->next->value;
	if (a < b)
		return ;
	else if (b < a)
		sa(head);
}
