/*
 *  subset.c - the next subset algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#include <subset.h>

unsigned int MBnext_subset(unsigned int *ar, size_t n)
{
	unsigned int finished = 0;
	unsigned int changed = 0;
	unsigned int i;

	for (i = n - 1; !finished && !changed; i--) {
		if (ar[i] == 0) {
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
