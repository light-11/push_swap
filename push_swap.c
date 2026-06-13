/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/13 23:12:00 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int	compute_disorder(stack a)
{
	int	mistakes;
	int	total_pairs;
	int	i;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size(a))
	{
		while (i + 1 < size(a))
		{
			if (a[i] > a[i + 1])
				mistakes++;
			total_pairs++;
		}
	}
	return (mistakes / total_pairs);
}

int	push_swap(int *list)
{
	int	disorder;

	disorder = compute_disorder(list);
	if (disorder == 0)
		return (0);
}
