/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:42:29 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/05 21:42:48 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				rank;
	struct s_list	*next;
}					t_list;

/* utils */
int					ft_atoi(char *nptr);
int					ft_strlen(char *s);
int					ft_strncmp(char *s1, char *s2);
int					ft_isdigit(char c);
void				coordinate_compression(t_list **stack_a);

/* list */
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, int content);
t_list				*ft_lstlast(t_list *lst);
int					count_node(t_list **stack);

/* check */
int					check_duplication(t_list **stack_a, int value);
float				compute_disorder(t_list **stack_a);
void				check_adaptive(float disorder, t_list **stack_a,
						t_list **stack_b);

/* sort */
int					push_swap(int argc, char *argv[]);
void				simple(t_list **stack_a, t_list **stack_b);
void				medium(t_list **stack_a, t_list **stack_b);
void				complex(t_list **stack_a, t_list **stack_b);
int					small_search(t_list **stack);

/* operations */
void				swap_a(t_list **stack);
void				swap_b(t_list **stack);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack);
void				rotate_b(t_list **stack);
void				reverse_rotate_a(t_list **stack);
void				reverse_rotate_b(t_list **stack);

/* bench */
void				bench(void);

#endif
