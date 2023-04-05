#include "search.h"

/**
 * list_check - check for value in list
 * @node: pointer of node
 * @value: pointer of the first node
 * Return: addres pointer
 *
 */

skiplist_t *list_check(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		if (node->n == value)
		{
			return (node);
		}
	}
	return (NULL);
}
/**
 * linear_skip -  search a value in a sorted list
 * @list: pointer to head
 * @value: int value to search
 * Return: pointer first node
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node, *prev_node, *temp_node;

	if (list == 0)
	{
		return (NULL);
	}
	current_node = list;
	while (current_node)
	{
		if (current_node->express == NULL)
		{
			prev_node = current_node->express;
			for (temp_node = list; temp_node;
			     temp_node = temp_node->next)
				if (temp_node->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					       current_node->index,
					       temp_node->index);
					break;
				}
			break;
		}
		if (current_node->express->n >= value)
		{
			prev_node = current_node->express;
			printf("Value checked at index [%lu] = [%d]\n",
			       prev_node->index, prev_node->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       current_node->index, prev_node->index);
			break;
		}
		current_node = current_node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       current_node->index, current_node->n);
	}
	return (list_check(current_node, value));
}
