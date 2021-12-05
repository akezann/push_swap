/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:39:55 by ak1337            #+#    #+#             */
/*   Updated: 2021/12/05 01:36:05 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int     get_max(int *lis, int len)
{
    int max = lis[0];
    int i = 1;
    while (i < len)
    {
        if (lis[i] > max)
            max = lis[i];
        i++;
    }
    return max;
}

int     check_for_double(int *arr, int k, int max)
{
    int j = 0;
    
    while (j < max)
    {
        if (arr[j] < k)
            return (1);
        j++;
    }
    return (0);
}

int     get_pos(int *arr, int k, int len, int max)
{
    int i = 0;
    int pos;
    while (i < len)
    {
        if (arr[i] == k && check_for_double(arr, k, i))
            pos = i;
        i++;
    }
    return (pos);
}

int     *ft_lis(int *arr, int n)
{
    int *lis;
    lis = malloc(n * sizeof(int));
    
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {  
                lis[i] = lis[j] + 1; 
            }
        }
    }
    return lis;
}

int     *insert_lis(int *arr, int len)
{
    int *lis;
    lis = ft_lis(arr, len);
    int max = get_max(lis, len);
    int *lisContent;
    lisContent = malloc(sizeof(int) * max);
    int pos;
    int i = 0;
    int j = 0;
    int k = 1;
    int c = 1;
    while (k <= max)
    {
        pos = get_pos(lis, k, len, max);
        lisContent[j++] = arr[pos];
        k++;
    }
    return (lisContent);
}