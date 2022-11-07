#include "sort.h"

/**
 * len_list - return the length of the list
 * @h : pointer to the list
 *
 * Return: int(length)
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sort the list with insert sort algorism
 * @list : the list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *one = NULL, *two = NULL;
	listint_t *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr = *list;
	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;

			if(one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
