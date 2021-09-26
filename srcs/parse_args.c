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
		if (!check_dig_arg(ar[i]))
		{
			printf("Error: check digity of args.\n");
			exit(0);
		} else {
			printf("arg number %d is :  %d\n", i, ft_atoi(ar[i]));
		}
		i++;
	}
}

int main(int argc, char **ar)
{
	parse_args(ar, argc);
	return 0;
}