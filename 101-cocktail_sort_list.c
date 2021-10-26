#include "sort.h"

/**
 * cocktail_forward - forward selection sort
 * @rcur: cur reference
 * @rnxt: nxt reference
 * @rlo: lo reference
 * @rhi: hi reference
 * @rlist: list reference
 * @rin_hi: in_hi reference
 *
 * Return: void
 */
void cocktail_forward(listint_t **rcur, listint_t **rnxt, listint_t **rlo,
					  listint_t **rhi, listint_t ***rlist, char *rin_hi)
{
	listint_t *cur = *rcur, *nxt = *rnxt, *lo = *rlo, *hi = *rhi,
		**list = *rlist;
	char in_hi = *rin_hi;

	while (1)
	{
		nxt = cur->next;
		if (in_hi || nxt == hi)
			in_hi = 1;
		if (nxt != NULL && cur->n > nxt->n)
		{
			if (cur->prev != NULL)
				cur->prev->next = nxt;
			nxt->prev = cur->prev;
			if (nxt->next != NULL)
				nxt->next->prev = cur;
			cur->next = nxt->next;
			nxt->next = cur;
			cur->prev = nxt;
			if (cur == lo)
				lo = nxt;
			if (cur == *list)
				*list = nxt;
			print_list(*list);
		}
		else if (in_hi)
		{
			if (nxt == hi)
				hi = cur;
			break;
		}
		else
			cur = nxt;
	}
	*rcur = cur, *rnxt = nxt, *rlo = lo, *rhi = hi, *rlist = list;
	*rin_hi = in_hi;
}

/**
 * cocktail_backward - backward selection sort
 * @rcur: cur reference
 * @rprv: prv reference
 * @rnxt: nxt reference
 * @rlo: lo reference
 * @rhi: hi reference
 * @rlist: list reference
 * @rin_lo: in_lo reference
 *
 * Return: void
 */
void cocktail_backward(listint_t **rcur, listint_t **rprv, listint_t **rnxt,
					   listint_t **rlo, listint_t **rhi, listint_t ***rlist,
					   char *rin_lo)
{
	listint_t *cur = *rcur, *prv = *rprv, *nxt = *rnxt, *lo = *rlo, *hi = *rhi,
		**list = *rlist;
	char in_lo = *rin_lo;

	while (1)
	{
		prv = cur->prev;
		if (in_lo || prv == lo)
			in_lo = 1;
		if (prv != NULL && cur->n < prv->n)
		{
			if (cur->next != NULL)
				cur->next->prev = prv;
			prv->next = cur->next;
			if (prv->prev != NULL)
				prv->prev->next = cur;
			cur->prev = prv->prev;
			prv->prev = cur;
			cur->next = prv;
			if (cur == hi)
				hi = prv;
			if (prv == *list)
				*list = cur;
			print_list(*list);
		}
		else if (in_lo)
		{
			if (prv == lo)
				lo = cur;
			break;
		}
		else
			cur = prv;
	}
	*rcur = cur, *rnxt = nxt, *rprv = prv, *rlo = lo, *rhi = hi, *rlist = list;
	*rin_lo = in_lo;
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
	char in_lo = 0, in_hi = 0;

	if (list != NULL && *list != NULL)
	{
		lo = *list;
		while (lo != hi)
		{
			cur = lo;
			in_hi = 0;
			cocktail_forward(&cur, &nxt, &lo, &hi, &list, &in_hi);

			cur = hi->prev;
			if (cur != NULL)
				cocktail_backward(&cur, &nxt, &prv, &lo, &hi, &list, &in_lo);
		}
	}
}
