/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:31:52 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/05 13:26:49 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **head)
{
	long	i;
	int		len;
	t_list	*current;

	i = 0;
	len = ft_lenstck(*head) / 2;
	if (head == NULL || *head == NULL || len == 0)
		return ;
	current = *head;
	while (1)
	{
		current->index = i;
		if (i <= len)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
		if (current == *head)
			break ;
	}
}

t_list	*find_best_match(t_list **head_a, t_list *head_b)
{
	long	match;
	t_list	*target;
	t_list	*current;

	if (head_a == NULL || head_b == NULL || *head_a == NULL)
		return (NULL);
	current = *head_a;
	match = LONG_MAX;
	while (1)
	{
		if (current->value > head_b->value && current->value < match)
		{
			match = current->value;
			target = current;
		}
		current = current->next;
		if (current == *head_a)
			break ;
	}
	if (match == LONG_MAX)
		target = find_smallest(head_a);
	return (target);
}

void	set_target(t_list **head_a, t_list **head_b)
{
	t_list	*current;
	t_list	*target;

	if (head_a == NULL || head_b == NULL || *head_a == NULL || *head_b == NULL)
		return ;
	current = *head_b;
	while (1)
	{
		target = find_best_match(head_a, current);
		current->target_node = target;
		current = current->next;
		if (current == *head_b)
			break ;
	}
}

void	set_price(t_list **head_a, t_list **head_b)
{
	int		len_a;
	int		len_b;
	t_list	*current_b;

	len_a = ft_lenstck(*head_a);
	len_b = ft_lenstck(*head_b);
	if (head_a == NULL || head_b == NULL || *head_a == NULL || *head_b == NULL)
		return ;
	current_b = *head_b;
	while (1)
	{
		current_b->push_price = current_b->index;
		if (!(current_b->above_median))
			current_b->push_price = len_b - (current_b->index);
		if (current_b->target_node->above_median)
			current_b->push_price += current_b->target_node->index;
		else
			current_b->push_price += len_a - (current_b->target_node->index);
		current_b = current_b->next;
		if (current_b == *head_b)
			break ;
	}
}

void	set_cheapest(t_list **head_b)
{
	long	match;
	t_list	*match_node;
	t_list	*current_b;

	if (head_b == NULL || *head_b == NULL)
		return ;
	match = LONG_MAX;
	match_node = NULL;
	current_b = *head_b;
	while (1)
	{
		if (current_b->push_price < match)
		{
			match = current_b->push_price;
			match_node = current_b;
		}
		current_b = current_b->next;
		if (current_b == *head_b)
			break ;
	}
	if (match_node != NULL)
		match_node->cheapest = true;
}
