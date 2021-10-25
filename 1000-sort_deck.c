#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

#define clen (52)

/**
 * istreq - case-insensitively compares 2 strings
 * @s1: a string
 * @s2: a string
 *
 * Return: 1 if they are equal, else 0
 */
char istreq(const char *s1, const char *s2)
{
	char c1, c2;

	if (s1 == NULL || s2 == NULL)
		return (s1 == s2);
	for (; *s1 && *s2; ++s1, ++s2)
	{
		c1 = *s1 >= 'A' && *s1 <= 'Z' ? *s1 + ('a' - 'A') : *s1;
		c2 = *s2 >= 'A' && *s2 <= 'Z' ? *s2 + ('a' - 'A') : *s2;
		if (c1 != c2)
			return (0);
	}
	return (*s1 == *s2);
}

/**
 * card_val - gets theinteger representation of a card
 * @card: a card
 *
 * Return: value of `card`
 */
int card_val(const card_t *card)
{
	const char *v = card->value;
	/* kind_t k = card->kind; */
	int num = istreq(v, "Ace") ? 1 : istreq(v, "2") ? 2
		: istreq(v, "3") ? 3 : istreq(v, "4") ? 4
		: istreq(v, "5") ? 5 : istreq(v, "6") ? 6
		: istreq(v, "7") ? 7 : istreq(v, "8") ? 8
		: istreq(v, "9") ? 9 : istreq(v, "10") ? 10
		: istreq(v, "Jack") ? 11 : istreq(v, "Queen") ? 12
		: istreq(v, "King") ? 13 : 0;
	return (((num - 1) * 4) + card->kind);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: a deck of cards
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *cur = NULL, *nxt = NULL, *cards[clen], *ci = *deck, *tmp;
	char sorted = 1;
	int i = 0, j;

	while (ci != NULL)
	{
		cards[i++] = ci;
		ci = ci->next;
	}
	do {
		sorted = 1;
		for (i = 0; i < clen - 1; ++i)
			if (card_val(cards[i]->card) > card_val(cards[i + 1]->card))
			{
				sorted = 0;
				tmp = cards[i];
				cards[i] = cards[i + 1];
				cards[i + 1] = tmp;
			}
	} while (!sorted);

	for (j = 0; j < clen; ++j)
	{
		cur = cards[j];
		nxt = j + 1 == clen ? NULL : cards[j + 1];

		if (j == 0)
			cur->prev = NULL;
		cur->next = nxt;
		if (nxt != NULL)
			nxt->prev = cur;
	}
	*deck = cards[0];
}
