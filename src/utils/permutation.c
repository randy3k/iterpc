#include "permutation.h"

static void swap(unsigned int *ar, unsigned int first, unsigned int second)
{
    unsigned int temp = ar[first];
    ar[first] = ar[second];
    ar[second] = temp;
}

static void reverse(unsigned int *ar, size_t len)
{
    unsigned int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        swap(ar, i, j);
    }
}

unsigned int next_permutation(unsigned int *ar, size_t len)
{
    unsigned int i1, i2;
    unsigned int result = 0;

    /* Trival for only one element */
    if (len == 1) {
        return result;
    }
    /* Find the rightmost element that is the first in a pair in ascending order */
    for (i1 = len - 2, i2 = len - 1; ar[i2] <= ar[i1] && i1 != 0; i1--, i2--);
    if (ar[i2] <= ar[i1]) {
        /* If not found, array is highest permutation */
        reverse(ar, len);
    }
    else {
        /* Find the rightmost element to the right of i1 that is greater than ar[i1] */
        for (i2 = len - 1; i2 > i1 && ar[i2] <= ar[i1]; i2--);
        /* Swap it with the first one */
        swap(ar, i1, i2);
        /* Reverse the remainder */
        reverse(ar + i1 + 1, len - i1 - 1);
        result = 1;
    }
    return result;
}
