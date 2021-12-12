/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:10:05 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/10 23:03:13 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		check_dig_arg(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

void		parse_args(char **ar, int argc)
{
	int i;

	i = 1;
	while (ar[i] && i < argc)
	{
		if (!check_dig_arg(ar[i]) ||
			(ft_strlen(ar[i]) == 10 && ft_strncmp(ar[i], "2147483647", 10) < 0) ||
			(ft_strlen(ar[i]) == 11 && ft_strncmp(ar[i], "-2147483648", 11) > 0) ||
			ft_strlen(ar[i]) > 11)
		{
			ft_exitError();
		}
		i++;
	}
}

void		push_args_to_stack(t_stack *s, char **arg, int argc)
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		if (arg[i] )
			s_push(s, ft_atoi(arg[i]));
		else
			ft_exitError();
		i--;
	}
}

void		push_args_to_array(t_array *arr, char **arg, int argc)
{
	int i;
	int j; 

	i = 1;
	j = 0;
	arr->array = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		if (arg[i])
			arr->array[j++] = ft_atoi(arg[i]);
		else
			ft_exitError();
		i++;
	}
}