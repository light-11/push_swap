/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/15 22:46:16 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int	ft_atoi(char *nptr)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(num * minus));
}

t_list	*ft_lstnew(void *int_a1)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
}

int	compute_disorder(int count, char *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < count - 2)
	{
		while (i + 1 < count - 2)
		{
			if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
				mistakes++;
			total_pairs++;
		}
	}
	return (mistakes / total_pairs);
}

int	push_swap(int argc, char *argv[])
{
	int		disorder;
	int		i;
	int		int_a;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 2;
	disorder = compute_disorder(agc, argv);
	if (disorder == 0)
		return (0);
	stack_a = ft_lstnew(ft_atoi(argv[1]));
	stack_b = ft_lstnew(ft_atoi(argv[1]));
	while (argc > i)
	{
		ft_lstadd_back(&stack_a, ft_atoi(argv[i]));
		ft_lstadd_back(&stack_b, NULL);
	}
}
