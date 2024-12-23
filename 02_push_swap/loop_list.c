/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:42:37 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 10:42:39 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	lstadd_head(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*tail;

	new_node = lstnew(value);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		tail = (*head)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void	lstadd(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*tail;

	new_node = lstnew(value);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = (*head)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *head;
		(*head)->prev = new_node;
	}
}

void	lstdelone(t_list **head, t_list *node)
{
	if (node == NULL || *head == NULL)
		return ;
	if (node->next == node)
		*head = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (*head == node)
			*head = node->next;
	}
	free(node);
}

void	lstclear(t_list **head)
{
	t_list	*current;
	t_list	*next_node;

	current = *head;
	if (*head == NULL)
		return ;
	while (1)
	{
		next_node = current->next;
		lstdelone(head, current);
		if (next_node == *head)
			break ;
		current = next_node;
	}
	*head = NULL;
}
