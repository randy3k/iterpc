/*
 *  subset.c - the next subset algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#include <subset.h>

unsigned int MBnext_subset(unsigned int *ar, size_t n)
{
	/* Find the first 1 with a 0 on its right, or the number of 1s */
	unsigned int i;
	unsigned int found = 0, finished = 0, ones = 0;
	unsigned int result = 1;

	for (i = n - 2; !found && !finished; i--) {
		found = ar[i] == 1 && ar[i + 1] == 0;
		finished = i == 0;
		ones += ar[i + 1] == 1;
	}
	if (found) {
		/* Move the 1 right */
		ar[i + 1] = 0;
		ar[i + 2] = 1;
	}
	else  if (ar[i + 1] == 0) {
		/* Add a new 1 and place them all at the beginning */
		for (i = 0; i < n; i++) {
			if (i < ones + 1) {
				ar[i] = 1;
			}
			else {
				ar[i] = 0;
			}
		}
	}
	else {
		/* Finished */
		for (i = 0; i < n; i++) {
			ar[i] = 0;
		}
		result = 0;
	}
	return result;
}
