
#include "push_swap.h"

void	ft_printf_list(t_list *head)
{
{
    if (head == NULL)
        return;

    t_list *current = head;

    do {
        printf("Value: %d\n", current->value); // Stampa il valore del nodo corrente
        current = current->next;
    } while (current != head); // Continua finché non torni alla testa
}
}

int	main(int argc, char **argv)
{
	t_list	*head;
	head = lstnew(-1);

	
	lstadd(&head, 0);
	lstadd(&head, 1);
	lstadd(&head, 2);
	lstadd(&head, 3);
	lstadd(&head, 4);
	lstadd(&head, 5);
	lstadd(&head, 6);
	lstadd(&head, 7);
	lstadd(&head, 8);
	ft_printf_list(head);
}
