#include "sort.h"


/**
 * insertion_sort_list - performs insertion sort on a linked list
 * @list: a linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ind = NULL, *cur = NULL, *nxt = NULL;
	char sorted = 1;

	if (list != NULL && *list != NULL)
		for (cur = *list; cur->next != NULL; cur = sorted ? cur : cur->next)
		{
			nxt = cur->next;
			ind = cur;
			sorted = 1;
			while (ind != NULL && nxt->n < ind->n)
			{
				sorted = 0;
				if (ind->prev != NULL)
					ind->prev->next = nxt;
				else
					*list = nxt;
				nxt->prev = ind->prev;

				if (nxt->next != NULL)
					nxt->next->prev = ind;
				ind->next = nxt->next;

				nxt->next = ind;
				ind->prev = nxt;

				ind = nxt->prev;
				print_list(*list);
			}
		}
}
