/*
 *  partition.c - the next partition algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#include <partition.h>

unsigned int MBnext_partition(unsigned int *ar, size_t len)
{	
	unsigned int result = 0;
	if (ar[len - 1] < len - 1) {
		unsigned int i;
		unsigned int finished = 0;
		unsigned int changed = 0;
		/* Find the rightmost element no more than the other elements */
		for (i = len - 1; !finished && !changed; i--) {
			unsigned int j, max = 0;
			/* Find the highest element to the left of this one */
			for (j = 0; j < i; j++) {
				if (ar[j] > max) {
					max = ar[j];
				}
			}
			if (ar[i] <= max) {
				/* Increment */
				ar[i]++;
				changed = 1;
				/* Set the following elements to 0 */
				for (j = i + 1; j < len; j++) {
					ar[j] = 0;
				}
			}
			finished = i == 1;
		}
		result = 1;
	}
	else {
		/* Reset to first partition */
		unsigned int i;
		for (i = 0; i < len; i++) {
			ar[i] = 0;
		}
	}

	return result;
}

