#include "sort.h"

/**
 * swap - swaps a node with the next node
 * @node: a doubly-linked list node
 *
 * Return: void
 */
void swap(listint_t *node)
{
	listint_t *node_1 = node, *node_2 = node->next;

	if (node_1->prev != NULL)
		node_1->prev->next = node_2;
	node_2->prev = node_1->prev;
	if (node_2->next != NULL)
		node_2->next->prev = node_1;
	node_1->next = node_2->next;
	node_2->next = node_1;
	node_1->prev = node_2;
}

/**
 * cocktail_sort_list - performs cocktail sort on a linked list
 * @list: a linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *lo = NULL, *hi = NULL, *cur = NULL, *nxt = NULL, *prv = NULL;

	if (list != NULL && *list != NULL)
	{
		lo = *list;
		while (lo != hi)
		{
			cur = lo, nxt = cur->next;
			while (nxt != NULL && nxt != hi)
			{
				if (cur->n > nxt->n)
				{
					swap(cur);
					if (nxt->prev == NULL)
						*list = nxt, lo = nxt;
					print_list(*list);
				}
				else
					cur = nxt;
				nxt = cur->next;
			}
			hi = cur, prv = cur->prev;
			while (prv != NULL)
			{
				if (cur->n < prv->n)
				{
					swap(prv);
					if (*list == prv)
						*list = cur, lo = cur;
					print_list(*list);
				}
				else
					cur = prv;
				prv = cur->prev;
			}
			lo = cur;
		}
	}
}
