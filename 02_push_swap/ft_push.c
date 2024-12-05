
#include "push_swap.h"
void pa(t_list **head_a, t_list **head_b)
{
    int tmp;

    if (*head_b == NULL)
        return;
    tmp = (*head_b)->value;
    if (*head_a == NULL)
        *head_a = lstnew(tmp);
    else
        lstadd_head(head_a, tmp);
    
    t_list *old_head_b = *head_b; // Salva il vecchio nodo di testa
    lstdelone(head_b, old_head_b); // Aggiorna correttamente il puntatore
    write(1, "pa\n", 3);
}

void pb(t_list **head_b, t_list **head_a)
{
    int tmp;

    if (*head_a == NULL)
        return;
    tmp = (*head_a)->value;
    if (*head_b == NULL)
        *head_b = lstnew(tmp);
    else
        lstadd_head(head_b, tmp);

    t_list *old_head_a = *head_a; // Salva il vecchio nodo di testa
    lstdelone(head_a, old_head_a); // Aggiorna correttamente il puntatore
    write(1, "pb\n", 3);
}

