/*
 *  multiset-combination.c - the next combination of a multiset algorithm
 *  Copyright (C) 2010 Martin Broadhurst  
 *  www.martinbroadhurst.com
 */

#include <multiset-combination.h>

unsigned int MBnext_multiset_combination(const unsigned int *multiset, unsigned int *ar, size_t n, unsigned int k)
{
	unsigned int finished = 0;
	unsigned int changed = 0;
	unsigned int i;

	for (i = k - 1; !finished && !changed; i--) {
		if (ar[i] < multiset[i + (n - k)]) {
			/* Find the successor */
			unsigned int j;
			for (j = 0; multiset[j] <= ar[i]; j++);
			/* Replace this element with it */
			ar[i] = multiset[j];
			if (i < k - 1) {
				/* Make the elements after it the same as this part of the multiset */
				unsigned int l;
				for (l = i + 1, j = j + 1; l < k; l++, j++) {
					ar[l] = multiset[j];
				}
			}
			changed = 1;
		}
		finished = i == 0;
	}
	if (!changed) {
		/* Reset to first combination */
		for (i = 0; i < k; i++) {
			ar[i] = multiset[i];
		}
	}
	return changed;
}
