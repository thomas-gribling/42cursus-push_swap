/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:46:21 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:19:17 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	tab_min(int *tab, size_t size)
{
	size_t	i;
	size_t	i_min;

	i_min = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] < tab[i_min])
			i_min = i;
		i++;
	}
	return (tab[i_min]);
}

int	is_sorted(int *tab, size_t size, int ascending)
{
	size_t	i;

	i = -1;
	if (ascending)
	{
		while (++i < size - 1)
			if (tab[i] > tab[i + 1])
				return (0);
	}
	else
	{
		while (++i < size - 1)
			if (tab[i] < tab[i + 1])
				return (0);
	}
	return (1);
}

void	tab_sort(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	int		mini;
	int		tmp;

	i = -1;
	while (++i < size)
	{
		mini = i;
		j = i;
		while (++j < size)
			if (tab[mini] > tab[j])
				mini = j;
		tmp = tab[i];
		tab[i] = tab[mini];
		tab[mini] = tmp;
	}
}
