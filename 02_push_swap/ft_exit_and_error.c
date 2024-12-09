/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:07:35 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/05 18:34:02 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_free(t_list **head, char **str, bool control)
{
	if (!(head == NULL || *head == NULL))
		free_stack(head);
	if (control == true)
		free_argv(str);
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_isdigit(int ch)
{
	if (ch == '-' || ch == '+')
		return (1);
	else if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

int	ft_istrdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

void	free_argv(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_list **head)
{
	t_list	*current;
	t_list	*next;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (next == *head)
			break ;
	}
	*head = NULL;
}
