/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:10 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 21:57:00 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *nptr)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if ('0' <= nptr[i] && nptr[i] <= '9')
			num = num * 10 + (nptr[i] - '0');
		else
			return (0);
		i++;
		if (-2147483648 > num * minus || num * minus > 2147483647)
			return (0);
	}
	if ((minus == -1 && i < 2) || i < 1)
		return (0);
	return (1);
}

float	compute_disorder(t_list **stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*now_node;
	t_list	*next_node;

	mistakes = 0;
	total_pairs = 0;
	now_node = *stack_a;
	next_node = (*stack_a)->next;
	while (now_node->next != NULL)
	{
		while (next_node != NULL)
		{
			if ((now_node->content) > (next_node->content))
				mistakes++;
			total_pairs++;
			next_node = next_node->next;
		}
		now_node = now_node->next;
		next_node = now_node->next;
	}
	return (mistakes / total_pairs);
}

int	check_duplication(t_list **stack_a, int value)
{
	t_list	*check_node;

	check_node = *stack_a;
	if (check_node == NULL)
		return (1);
	while (check_node->next != NULL)
	{
		if (check_node->content == value)
			return (0);
		check_node = check_node->next;
	}
	if (check_node->content == value)
		return (0);
	return (1);
}

void	coordinate_compression(t_list **stack_a)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

	if (stack_a == NULL || *stack_a == NULL || ((*stack_a)->next == NULL))
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		rank = 0;
		compare = *stack_a;
		while (compare != NULL)
		{
			if (current->content > compare->content)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

void	check_adaptive(float disorder, t_list **stack_a, t_list **stack_b,
		t_command_flag *command_flag)
{
	if (count_node(stack_a) <= 30)
	{
		command_flag ->is_simple = 1;
		simple(stack_a, stack_b, command_flag);
	}
	else
	{
		if (disorder < 0.2)
		{
			command_flag ->is_simple = 1;
			simple(stack_a, stack_b, command_flag);
		}
		if (0.2 <= disorder && disorder < 0.5)
		{
			command_flag ->is_medium = 1;
			medium(stack_a, stack_b, command_flag);
		}
		if (0.5 <= disorder)
		{
			command_flag ->is_complex = 1;
			complex(stack_a, stack_b, command_flag);
		}
	}
}
