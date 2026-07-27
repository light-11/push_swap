/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 17:40:10 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	float		disorder;
	t_command	command;
	t_flag		flag;

	initialize_command(&command);
	initialize_flag(&flag);
	stack_a = NULL;
	stack_b = NULL;
	if (!make_stack_a(argc, argv, &stack_a))
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
	is_flag(argc, argv, &flag);
	flag_branch(&stack_a, &stack_b, &command, &flag, disorder);
	free_stack(&stack_a);
	return (free_stack(&stack_b));
}

int	make_stack_a(int argc, char *argv[], t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			i++;
		else
		{
			if (!check_number(argv[i]))
				return (0);
			if (*stack_a == NULL)
				*stack_a = ft_lstnew(ft_atoi(argv[i]));
			else
			{
				if (!check_duplication(stack_a, ft_atoi(argv[i])))
					return (0);
				ft_lstadd_back(stack_a, ft_atoi(argv[i]));
			}
			i++;
		}
	}
	return (1);
}

void	is_flag(int argc, char *argv[], t_flag *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench"))
			flag->is_bench++;
		if (ft_strncmp(argv[i], "--simple") && flag->is_simple == 0
			&& flag->is_medium == 0 && flag->is_complex == 0
			&& flag->is_adaptive == 0)
			flag->is_simple++;
		if (ft_strncmp(argv[i], "--medium") && flag->is_simple == 0
			&& flag->is_medium == 0 && flag->is_complex == 0
			&& flag->is_adaptive == 0)
			flag->is_medium++;
		if (ft_strncmp(argv[i], "--complex") && flag->is_simple == 0
			&& flag->is_medium == 0 && flag->is_complex == 0
			&& flag->is_adaptive == 0)
			flag->is_complex++;
		if (ft_strncmp(argv[i], "--adaptive") && flag->is_simple == 0
			&& flag->is_medium == 0 && flag->is_complex == 0
			&& flag->is_adaptive == 0)
			flag->is_adaptive++;
		i++;
	}
}

int	flag_branch(t_list **stack_a, t_list **stack_b, t_command *command,
		t_flag *flag, float disorder)
{
	if (flag->is_simple == 1)
		simple(stack_a, stack_b, command);
	else if (flag->is_medium == 1)
		medium(stack_a, stack_b, command);
	else if (flag->is_complex == 1)
		complex(stack_a, stack_b, command);
	else if (flag->is_adaptive == 1)
		check_adaptive(disorder, stack_a, stack_b, command, flag);
	else if (flag->is_simple == 0 && flag->is_medium == 0
		&& flag->is_complex == 0 && flag->is_adaptive == 0)
	{
		flag->is_adaptive = 1;
		check_adaptive(disorder, stack_a, stack_b, command, flag);
	}
	else
		return (0);
	if (flag->is_bench == 1)
		bench(command, flag, disorder);
	return (0);
}

int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
	// tmp = *stack_a;
	// while (tmp)
	// {
	// 	printf("%d\n", tmp->content);
	// 	tmp = tmp->next;
	// }
	// printf("%d\n", command->pa);
	// printf("%d\n", command->pb);
	// printf("%d\n", command->sa);
	// printf("%d\n", command->sb);
	// printf("%d\n", command->ra);
	// printf("%d\n", command->rra);
}
