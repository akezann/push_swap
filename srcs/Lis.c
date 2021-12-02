/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:39:55 by ak1337            #+#    #+#             */
/*   Updated: 2021/11/30 19:40:14 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int     get_max(int *lis, int len)
{
    int max = lis[0];
    int i = 1;
    while (i < len )
    {
        if (lis[i] > max)
            max = lis[i];
        i++;
    }
    return max;
}

int     check_for_double(int *arr, int element, int start, int len)
{
    while (start < len)
    {
        if (arr[start] == element)
            return (1);
        start++;
    }
    return (0);
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
    int i = 0;
    int j = 0;
    int k = 1;
    while (i < len)
    {
        while (lis[i] == lis[i + 1])
            i++;
        if (lis[i] == k)
        {
            k++;
            lisContent[j++] = arr[i];
        }
        i++;
    }
    return (lisContent);
}

// int main()
// {
//     int tab[8] = {5, 2, 8, 6, 3, 6, 9,7};
//     int *lis;
//     lis = insert_lis(tab, 8);
    
//     int i = 0;
//     while (i < get_max(ft_lis(tab, 8), 8))
//     {
//         printf("|%d|", lis[i++]);
//     }
// }