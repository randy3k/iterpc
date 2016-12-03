/*
 *  multicombination.c - the next multicombination algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#include <multicombination.h>

unsigned int MBnext_multicombination(unsigned int *ar, size_t n, unsigned int k)
{
	unsigned int finished = 0;
	unsigned int changed = 0;
	unsigned int i;

	for (i = k - 1; !finished && !changed; i--) {
		if (ar[i] < n - 1) {
			/* Increment this element */
			ar[i]++;
			if (i < k - 1) {
				/* Make the elements after it the same */
				unsigned int j;
				for (j = i + 1; j < k; j++) {
					ar[j] = ar[j - 1];
				}
			}
			changed = 1;
		}
		finished = i == 0;
	}
	if (!changed) {
		/* Reset to first combination */
		for (i = 0; i < k; i++) {
			ar[i] = 0;
		}
	}
	return changed;
}
