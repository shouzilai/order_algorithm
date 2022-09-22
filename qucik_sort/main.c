#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "quick_sort.h"

INT data[10] = {4, 2, 6, 8, 1, 3, 9, 5, 7, 0};

INT print_array(INT array[], INT length)
{
    printf("array data is :");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}

int main()
{
    print_array(data, 10);

    quick_sort(data, 0, 9);

    print_array(data, 10);

    return 0;
}



