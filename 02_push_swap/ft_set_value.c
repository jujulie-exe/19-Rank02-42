/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:31:52 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/04 11:08:04 by jfranco          ###   ########.fr       */
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

void	set_price(t_list **head_a, t_list **head_b)
{
	int	len_a;
	int len_b;
	t_list	*current_b
	
	len_a = ft_lenstck(head_a);
	len_b = ft_lenstck(head_b);
	if (head_a == NULL || head_b == NULL || *head_a == NULL || *head_b == NULL)
		return ;
	current_b = *head_b;
	while (1)
	{
		current_b->push_price = b->index;
		if (!(current->above_median))
				current_b->push_price = len_b - (b->index);
		if (current_b->target_node->above_median)
			current_b->push_price += b->target_node->index;
		else 
			current_b->push_price += len_a - (current_b->target_node->index);
		if(current_b = *head_b)
			break ;
		current = current->next;

	}
}

void	set_cheapest(t_list **head_b)
{
	long	match;
	t_list	*match_node;
	t_list	*current_b;

	if (head_a == NULL || head_b == NULL || *head_a == NULL || *head_b == NULL)
		return ;
	match = LONG_MAX;
	while (1)
	{
		if (current->push_price < match)
		{
			match = current->push_price;
			match_node = current_b
		}
		if (current == *head)
			break ;
		current_b = current->next;
	}
	match_node->cheapset = true;
}
