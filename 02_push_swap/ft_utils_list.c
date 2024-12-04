/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:49 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/04 16:06:59 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*t_list	*find_last_node(t_list **head)
{
	t_list last_node;
	last_node->(*head)->prev;
	return (last_node);
}*/

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

t_list *return_cheapest(t_list **head)
{
	t_list *current;

	if (head == NULL || *head == NULL)
		return (NULL);
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
