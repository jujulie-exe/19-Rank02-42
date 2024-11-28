
#include "push_swap.h"

void	ft_printf_list(t_list *head)
{
    if (head == NULL)
        return;

    t_list *current = head;
    while (1)
    {
	    printf("Valore: %d\n", current->value);
	    current = current->next;
	    if (current == head)
		    break;
    }

}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*head_b;
	head = lstnew(-1);
	head_b = lstnew(9);

	
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
//////////////////ROTATE//////////////////////////
	printf("%s,\n","----------ROTATE---------");
	ra(&head);
	ft_printf_list(head);
	//////////////////reverse/////////////////////
	printf("---------REVERSE----------\n");
	rra(&head);
	ft_printf_list(head);
	///////////////////////SWAP////////////////////
	printf("%s\n","-------SWAP-------");
	sa(&head);
	ft_printf_list(head);
	/////////////////PUSH//////////////////////////
	printf("%s\n","-------SWAP-------");
	
	ft_printf_list(head);
	pa(&head_b, &head);
	printf("%s\n","DOPO L'USO DI PA LA MAIN STACK_A");
	ft_printf_list(head);
	printf("%s\n","head_b");
	ft_printf_list(head_b);
	printf("%s\n", "NON FOULT");
	return (0);




}
