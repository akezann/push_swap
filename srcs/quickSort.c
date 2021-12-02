#include "./../includes/push_swap.h"

static void       ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

static int         partition(int arr[], int low, int high)
{
    int     pivot = arr[high];

    int i = (low - 1);
    int  j = low;
    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            ft_swap(&arr[i], &arr[j]);
        }
        j++;
    }
   ft_swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *array, int low, int high)
{
  if (low < high) { 
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}