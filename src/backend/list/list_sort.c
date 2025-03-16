/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:59:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:59:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

static t_node	*list_sorted_merge(t_node *left, t_node *right,
		int64_t (*compare)(uintptr_t d1, uintptr_t d2))
{
	t_node	*result;

	result = NULL;
	if (!left)
		return (right);
	else if (!right)
		return (left);
	if (compare(left->data, right->data))
	{
		result = left;
		result->next = list_sorted_merge(left->next, right, compare);
		if (result->next)
			result->next->prev = result;
	}
	else
	{
		result = right;
		result->next = list_sorted_merge(left, right->next, compare);
		if (result->next)
			result->next->prev = result;
	}
	result->prev = NULL;
	return (result);
}

static void	list_find_middle(t_node *list, t_node **start, t_node **end)
{
	t_node	*fast;
	t_node	*slow;

	fast = list;
	slow = list;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		if (fast)
			slow = slow->next;
	}
	*start = list;
	*end = slow->next;
	if (*end)
		(*end)->prev = NULL;
	slow->next = NULL;
}

void	list_sort(t_node **list, int64_t (*compare)(uintptr_t d1, uintptr_t d2))
{
	t_node	*head;
	t_node	*a;
	t_node	*b;

	head = *list;
	a = NULL;
	b = NULL;
	if (!head || !head->next)
		return ;
	list_find_middle(head, &a, &b);
	list_sort(&a, compare);
	list_sort(&b, compare);
	*list = list_sorted_merge(a, b, compare);
}
