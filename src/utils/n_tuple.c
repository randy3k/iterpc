#include "n_tuple.h"

unsigned int next_n_tuple(unsigned int *ar, size_t len, const size_t *sizes)
{
    unsigned int changed = 0;
    unsigned int finished = 0;
    unsigned int i;

    for (i = len - 1; !changed && !finished; i--) {
        if (ar[i] < sizes[i] - 1) {
            /* Increment */
            ar[i]++;
            changed = 1;
        }
        else {
            /* Roll over */
            ar[i] = 0;
        }
        finished = i == 0;
    }

    return changed;
}
