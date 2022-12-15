#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert in sorted linked list
 * @head: pointer to head of list
 * @number: Number to add in linked list
 * Return: Address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *headNode;

	headNode = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = number;

	if (*head == NULL)
		*head = newNode;
	else
	{
		while (headNode->next != NULL && headNode->next->n <= number)
		{
			headNode = headNode->next;
		}
		if (headNode == *head)
		{
			newNode->next = headNode;
			*head = newNode;
		}
		else
		{
			newNode->next = (headNode->next == NULL) ? NULL : headNode->next;
			headNode->next = newNode;
		}
	}

	return (newNode);
}
