/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:04:06 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 19:10:19 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	check_for_duplicate(int	*array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				ft_exit_error();
			j++;
		}
		i++;
	}
}

char	**get_argv_split(char **argv, int *argc)
{
	int		i;
	char	*args;
	char	*save_addr;
	char	*arg;
	char	**argv1;

	args = ft_strdup("");
	if (*argc == 1)
		ft_exit_error();
	i = 0;
	while (++i < *argc)
	{
		save_addr = args;
		arg = ft_strjoin(argv[i], " ");
		args = ft_strjoin(args, arg);
		free(save_addr);
		free(arg);
	}
	argv1 = ft_split(args, " ");
	i = 0;
	while (argv1[i])
		i++;
	*argc = i;
	free(args);
	return (argv1);
}
