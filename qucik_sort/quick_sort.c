#include "quick_sort.h"


static INT swap(int *a, int *b)
{
    INT temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

INT quick_sort(INT array[], INT head, INT tail)
{
    if (array == NULL || head < 0 || tail < 0) {
        return -1;
    }
    INT low, hign, temp;

    low = head;
    hign = tail;

    if (low < hign) {
        temp = array[low];
        while (low < hign)
        {
            while(low < hign && temp < array[hign]) {
                hign--;
            }
            if (low < hign) {
                swap(&array[low++], &array[hign]);
            }

            while(low < hign && temp >= array[low]) {
                low++;
            }
            if (low < hign) {
                swap(&array[low], &array[hign--]);
            }
        }
        array[low] = temp;
        quick_sort(array, head, low - 1);
        quick_sort(array, low + 1, tail);
    }
    

    return 0;
}