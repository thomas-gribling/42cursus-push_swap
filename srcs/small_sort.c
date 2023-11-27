/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:57:07 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:19:09 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_convert(t_stack *a)
{
	int		*tmp;
	size_t	i;
	size_t	j;

	tmp = malloc((a->size + 1) * sizeof(int));
	i = -1;
	while (++i < a->size)
		tmp[i] = a->array[i];
	tab_sort(tmp, a->size);
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < a->size)
			if (tmp[i] == a->array[j])
				a->array[j] = i;
	}
	free(tmp);
}

static void	ft_sort_three(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if ((arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
		|| is_sorted(arr, a->size, 0))
		ps_do("sa", a, NULL);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		ps_do("sa", a, NULL);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		ps_do("ra", a, NULL);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		ps_do("rra", a, NULL);
}

static void	ft_sort_four(t_stack *a)
{
	t_stack	*b;
	int		find_int;

	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->array = NULL;
	find_int = 0;
	while (a->size > 2)
	{
		if (a->array[0] == find_int)
		{
			ps_do("pb", a, b);
			find_int++;
		}
		else if (stack_get_index(a, find_int) < 2)
			ps_do("ra", a, NULL);
		else
			ps_do("rra", a, NULL);
	}
	if (a->array[0] == 3)
		ps_do("sa", a, NULL);
	ps_do("pa", a, b);
	ps_do("pa", a, b);
	free_stack(&b);
}

static void	ft_sort_five(t_stack *a)
{
	t_stack	*b;
	int		find_int;

	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->array = NULL;
	find_int = 0;
	while (a->size > 3)
	{
		if (a->array[0] == find_int)
		{
			ps_do("pb", a, b);
			find_int++;
		}
		else if (stack_get_index(a, find_int) < 2)
			ps_do("ra", a, NULL);
		else
			ps_do("rra", a, NULL);
	}
	ft_sort_three(a);
	ps_do("pa", a, b);
	ps_do("pa", a, b);
	free_stack(&b);
}

void	ft_small_sort(t_stack *a)
{
	ft_convert(a);
	if (a->size == 2)
		ps_do("sa", a, NULL);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a);
	else if (a->size == 5)
		ft_sort_five(a);
}
