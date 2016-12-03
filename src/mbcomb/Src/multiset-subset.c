/*
 *  multiset-subset.c - the next subset of a multiset algorithm
 *  Copyright (C) 2010 Martin Broadhurst  
 *  www.martinbroadhurst.com
 */

#include <multiset-subset.h>

unsigned int MBnext_multiset_subset(const unsigned int *multiset, unsigned int *ar, size_t n)
{
	unsigned int finished = 0;
	unsigned int changed = 0;
	unsigned int i;

	for (i = n - 1; !finished && !changed; i--) {
		if (ar[i] < multiset[i]) {
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
	if (!changed) {
		/* Reset to first combination */
		for (i = 0; i < n; i++) {
			ar[i] = 0;
		}
	}
	return changed;
}
