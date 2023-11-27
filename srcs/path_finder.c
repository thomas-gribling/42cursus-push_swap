/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:05:27 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:19:01 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_moves(t_stack *stack, int i)
{
	int	dist;
	int	moves;

	dist = 0;
	moves = 0;
	while ((stack->size + dist) % stack->size != stack_get_index(stack, i))
	{
		if (stack_get_index(stack, i) > stack->size / 2)
			dist++;
		else
			dist--;
		moves++;
	}
	return (moves);
}

int	find_closest_path(t_stack *stack, int a, int b)
{
	if (get_moves(stack, a) + 2 > get_moves(stack, b) + 3)
		return (0);
	else
		return (1);
}

void	do_fast_push_a(t_stack *a, t_stack *b, int i)
{
	while (b->array[0] != i - 1)
	{
		if (stack_get_index(b, i - 1) > b->size / 2)
			ps_do("rrb", NULL, b);
		else
			ps_do("rb", NULL, b);
	}
	ps_do("pa", a, b);
	while (b->array[0] != i)
	{
		if (stack_get_index(b, i) > b->size / 2)
			ps_do("rrb", NULL, b);
		else
			ps_do("rb", NULL, b);
	}
	ps_do("pa", a, b);
	ps_do("sa", a, NULL);
}

void	do_fast_push_b(t_stack *a, t_stack *b, int i)
{
	while (a->array[0] != i + 1)
	{
		if (stack_get_index(a, i + 1) > a->size / 2)
			ps_do("rra", a, NULL);
		else
			ps_do("ra", a, NULL);
	}
	ps_do("pb", a, b);
	while (a->array[0] != i)
	{
		if (stack_get_index(a, i) > a->size / 2)
			ps_do("rra", a, NULL);
		else
			ps_do("ra", a, NULL);
	}
	ps_do("pb", a, b);
	ps_do("sb", NULL, b);
}
