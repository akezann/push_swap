/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:39:55 by ak1337            #+#    #+#             */
/*   Updated: 2021/12/06 03:16:56 by ak1337           ###   ########.fr       */
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
        if (arr[j] > k)
            return (0);
        j++;
    }
    return (1);
}

int     get_pos(int *arr, int k, int len)
{
    int i = len - 1;
    int pos = 0;
    while (i > -1)
    {
        if (arr[i] == k)
            return pos;
        i--;
    }
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
    int i = len - 1;
    int j = 0;
    int k = max;
    int c = 1;
    lisContent[0] = arr[0];
    while (i > -1)
    {
        if (lis[i] == k)
        {
            lisContent[j++] = arr[i];
            k--;
        }
        i--;
    }
    return (lisContent);
}