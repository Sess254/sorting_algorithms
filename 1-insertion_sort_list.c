/*
 * File: 1-insertion_sort_list.c
 * Auth: Sess254
 */


#include "sort.h"
void to_the_left(listint_t *cur, listint_t *insertion, listint_t **head);

/**
 * insertion_sort_list - sorts a doulbly linked list of ints using insertion
 * sort
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL;
	listint_t *insertion = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	insertion = cur->prev;
	while (cur)
	{
		insertion = cur->prev;
		while (insertion != NULL && insertion->n > cur->n)
		{
			to_the_left(cur, insertion, list);
			insertion = cur->prev;
		}
		cur = cur->next;
	}
}

/**
 * to_the_left - swaps members of a list
 * @cur: the current node tomove to the left of insertion
 * @insertion: pointer to the insertion
 * @head: pointer to head of the list
 */
void to_the_left(listint_t *cur, listint_t *insertion, listint_t **head)
{
	listint_t *swap_a = cur->next;
	listint_t *swap_b = insertion->prev;

	if (swap_a != NULL)
		swap_a->prev = insertion;
	if (swap_b != NULL)
		swap_b->next = cur;
	cur->prev = swap_b;
	insertion->next = swap_a;
	cur->next = insertion;
	insertion->prev = cur;
	if (*head == insertion)
		*head = cur;
	print_list(*head);
}
