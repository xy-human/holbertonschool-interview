#include "list.h"

/**
 * add_node_begin - Add a new node to the beginning
 * @list: double pointer to head of doubly circular linked list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *head = *list, *tail, *new_node;
	char *new_str = NULL;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	new_str = strdup(str);

	if (!new_node || !new_str)
		return (NULL);

	new_node->str = new_str;
	new_node->next = new_node;
	new_node->prev = new_node;

	if (head)
	{
		if (!head->next && !head->prev)
		{
			head->prev = head->next = new_node;
			new_node->prev = new_node->next = head;
		}
		else
		{
			tail = head->prev;

			tail->next = new_node;
			new_node->next = head;

			head->prev = new_node;
			new_node->prev = tail;
		}
	}

	*list = new_node;
	return (new_node);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: double pointer to head of doubly circular linked list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *head = *list, *tail, *new_node;
	char *new_str = NULL;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	new_str = strdup(str);

	if (!new_node || !new_str)
		return (NULL);

	new_node->str = new_str;
	new_node->next = new_node;
	new_node->prev = new_node;

	if (head)
	{
		if (!head->next && !head->prev)
		{
			head->prev = head->next = new_node;
			new_node->prev = new_node->next = head;
		}
		else
		{
			tail = head->prev;

			tail->next = new_node;
			new_node->next = head;

			head->prev = new_node;
			new_node->prev = tail;
		}
	}
	else
	{
		*list = new_node;
	}

	return (new_node);
}
