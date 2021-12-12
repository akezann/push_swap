/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:39:55 by ak1337            #+#    #+#             */
/*   Updated: 2021/12/10 23:23:26 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int     get_max(int *lis, int len)
{
    int max;
    int i;
    
    max = lis[0];
    i = 1;
    while (i < len)
    {
        if (lis[i] > max)
            max = lis[i];
        i++;
    }
    return (max);
}

int     *ft_lis(int *arr, int len)
{
    int *lis;
    int i;
    int j;
    
    lis = malloc(len * sizeof(int));
    lis[0] = 1;
    i = 0;
    while (++i < len)
    {
        lis[i] = 1;
        j = -1;
        while (++j < i)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {  
                lis[i] = lis[j] + 1; 
            }
        }
    }
    return (lis);
}

int     *insert_lis(int *arr, int len)
{
    int *lis;
    int max;
    int *lisContent;
    int i;
    int j;
    int k;
    
    lis = ft_lis(arr, len);
    max = get_max(lis, len);
    lisContent = malloc(sizeof(int) * max);
    i = len - 1;
    j = 0;
    k = max;
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