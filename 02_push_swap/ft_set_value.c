/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:31:52 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/03 17:44:56 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_index(t_list **head)
{
	long	i;
	int		len;
	t_list	*current;

	i = 0;
	len = ft_lenstck(head) / 2;
	if (head == NULL || *head == NULL || len == 0)
		return ;
	current = *head;
	while (1)
	{
		current->index = i;
		if (i >= len)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		if (current == *head)
			break ;
		i++
	}
}

t_list	*find_best_match(t_list **head_a, t_list *head_b)
{
	long	match;
	t_list	*target;
	t_list	*current;

	if (head_a == NULL || head_b == NULL || *head_a == NULL || *head_b == NULL)
		return ;
	current = *head_a
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



