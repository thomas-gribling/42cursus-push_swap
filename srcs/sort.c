/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:08:26 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:19:11 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_chunkb(t_stack *a, t_stack *b, int start, int end)
{
	while (stack_scan(a, start, end))
	{
		if (a->array[0] >= start && a->array[0] <= end)
			ps_do("pb", a, b);
		else
			ps_do("ra", a, NULL);
	}
}

void	sort_chunka(t_stack *a, t_stack *b, int start, int end)
{
	int	i;

	i = end;
	while (stack_scan(b, start, end))
	{
		if (b->array[0] == i)
		{
			ps_do("pa", a, b);
			i--;
		}
		else if (i == 0 || !find_closest_path(b, i, i - 1))
		{
			if (stack_get_index(b, i) > b->size / 2)
				ps_do("rrb", NULL, b);
			else
				ps_do("rb", NULL, b);
		}
		else
		{
			do_fast_push_a(a, b, i);
			i -= 2;
		}
	}
}

void	sort_chunkb(t_stack *a, t_stack *b, int start, int end)
{
	int		i;

	i = start;
	while (stack_scan(a, start, end))
	{
		if (a->array[0] == i)
		{
			ps_do("pb", a, b);
			i++;
		}
		else if ((size_t)i == a->size - 1 || !find_closest_path(b, i, i + 1))
		{
			if (stack_get_index(a, i) > a->size / 2)
				ps_do("rra", a, NULL);
			else
				ps_do("ra", a, NULL);
		}
		else
		{
			do_fast_push_b(a, b, i);
			i += 2;
		}
	}
}

void	ft_sort(t_stack *a)
{
	t_stack	*b;
	size_t	size;
	size_t	chunks;
	size_t	curr;

	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->array = NULL;
	ft_convert(a);
	size = a->size - 1;
	chunks = 11;
	if (a->size <= chunks)
		chunks = 4;
	if (a->size == 100)
		chunks = 5;
	curr = 0;
	push_chunkb(a, b, 0, size / chunks);
	while (++curr < chunks - 1)
		push_chunkb(a, b, size / chunks * curr + 1, size / chunks * (curr + 1));
	sort_chunkb(a, b, size / chunks * curr + 1, size);
	sort_chunka(a, b, 0, size);
	free_stack(&b);
}
