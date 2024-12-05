/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:07:35 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/05 18:09:32 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	exit_and_free(t_list **head, char **str)
{
	if (!(head == NULL || *head == NULL))
		lstclear(head);
	write(1, "Error\n", 6);
	free_argv(str);
	exit (0);
}


void	ft_check_double(t_list **head, char **argv)
{
	int	tmp;
	t_list	*current;

	if (head == NULL || *head == NULL)
		return ;

	current = *head;
	tmp = 0;
	if (!(*head == (*head)->next))
	{
		while (1)
		{
			tmp = current->value;
			current = current->next;
			if (tmp == current->value)
				exit_and_free(head, argv);
			if (current == *head)
				break ;
		}
	}
}

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int ft_istrdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if(!(ft_isdigit(s[i])))
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
	if (head == NULL || *head == NULL)
		return ;
	t_list *current = *head;
	t_list *next;
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

