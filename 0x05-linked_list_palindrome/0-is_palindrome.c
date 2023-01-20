#include "lists.h"

/**
 * is_palindrome - Function to know if linked list is a palindrome
 * @head: linked list header
 * Return: 1 if is palindrome, else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *initial = *head;
    int i = 0, j = 0;
    int k[4096];

    if (head == NULL || *head == NULL)
        return (1);
    while (initial->next)
        initial = initial->next, i++;
    initial = *head;
    while (initial)
    {
        k[j] = initial->n;
        initial = initial->next;
        j++;
    }
    initial = *head;
    while (initial)
    {
        if (initial->n == k[i])
            initial = initial->next;
        else
            return (0);
        i--;
    }
    return (1);
}
