/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:10:05 by akezanna          #+#    #+#             */
/*   Updated: 2021/09/26 15:41:09 by akezanna         ###   ########.fr       */
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

void		push_argsToStack(t_stack *s, char **arg, int argc)
{
	int i;

	i = argc - 1;
	parse_args(arg, argc);
	while (i > 0)
	{
		if (arg[i] )
			s_push(s, ft_atoi(arg[i]));
		else
			ft_exitError();
		i--;
	}
}
