#include "lists.h"

/**
 * check_cycle - Validate if singly linked list has a cycle.
 * @list: pointer to the head of the list.
 * Return: 0 if if not is a cycle, 1 if is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *first = list, *second = list;

	if (list == NULL)
		return (0);

	while (1)
	{
		first = first->next;

		if (second->next != NULL)
			second = second->next->next;
		else
			return (0);
		if (first == NULL || second == NULL)
			return (0);
		if (first == second)
			return (1);
	}
}
