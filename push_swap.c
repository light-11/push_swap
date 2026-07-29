/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/29 22:39:39 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;
	float			disorder;
	t_command_flag	command_flag;

	initialize_command_flag(&command_flag);
	stack_a = NULL;
	stack_b = NULL;
	if (!make_stack_a(argc, argv, &stack_a, &command_flag))
	{
		write(2, "Error\n", 6);
		return (free_stack(&stack_a));
	}
	if (stack_a == NULL || stack_a->next == NULL)
		return (free_stack(&stack_a));
	disorder = compute_disorder(&stack_a);
	if (disorder == 0)
		return (free_stack(&stack_a));
	coordinate_compression(&stack_a);
	flag_branch(&stack_a, &stack_b, &command_flag, disorder);
	free_stack(&stack_a);
	return (free_stack(&stack_b));
}

int	make_stack_a(int argc, char *argv[], t_list **stack_a,
		t_command_flag *command_flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!is_flag(argv[i], command_flag))
				return (0);
		}
		else
		{
			if (!check_number(argv[i]))
				return (0);
			if (*stack_a == NULL)
				*stack_a = ft_lstnew(ft_atoi(argv[i]));
			else if (!check_duplication(stack_a, ft_atoi(argv[i])))
				return (0);
			else
				ft_lstadd_back(stack_a, ft_atoi(argv[i]));
		}
		i++;
	}
	return (1);
}

int	is_flag(char *argv_i, t_command_flag *command_flag)
{
	if (ft_strncmp(argv_i, "--bench") && command_flag->is_bench == 0)
		command_flag->is_bench++;
	else if (ft_strncmp(argv_i, "--simple") && command_flag->is_simple == 0
		&& command_flag->is_medium == 0 && command_flag->is_complex == 0
		&& command_flag->is_adaptive == 0)
		command_flag->is_simple++;
	else if (ft_strncmp(argv_i, "--medium") && command_flag->is_simple == 0
		&& command_flag->is_medium == 0 && command_flag->is_complex == 0
		&& command_flag->is_adaptive == 0)
		command_flag->is_medium++;
	else if (ft_strncmp(argv_i, "--complex") && command_flag->is_simple == 0
		&& command_flag->is_medium == 0 && command_flag->is_complex == 0
		&& command_flag->is_adaptive == 0)
		command_flag->is_complex++;
	else if (ft_strncmp(argv_i, "--adaptive") && command_flag->is_simple == 0
		&& command_flag->is_medium == 0 && command_flag->is_complex == 0
		&& command_flag->is_adaptive == 0)
		command_flag->is_adaptive++;
	else
		return (0);
	return (1);
}

int	flag_branch(t_list **stack_a, t_list **stack_b,
		t_command_flag *command_flag, float disorder)
{
	if (command_flag->is_simple == 1)
		simple(stack_a, stack_b, command_flag);
	else if (command_flag->is_medium == 1)
		medium(stack_a, stack_b, command_flag);
	else if (command_flag->is_complex == 1)
		complex(stack_a, stack_b, command_flag);
	else if (command_flag->is_adaptive == 1)
		check_adaptive(disorder, stack_a, stack_b, command_flag);
	else if (command_flag->is_simple == 0 && command_flag->is_medium == 0
		&& command_flag->is_complex == 0 && command_flag->is_adaptive == 0)
	{
		command_flag->is_adaptive = 1;
		check_adaptive(disorder, stack_a, stack_b, command_flag);
	}
	else
		return (0);
	if (command_flag->is_bench == 1)
		bench(command_flag, disorder);
	return (0);
}

int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
}
