/*
 *  multiset-subsets.c - prints the vectors for the subsets of a multiset
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <multiset-subset.h>
#include <comb-util.h>

int main(void)
{
	unsigned int multiset[] = {1, 2, 1};
	const size_t n = sizeof(multiset) / sizeof(unsigned int);
	unsigned int numbers[] = {0, 0, 0};

	do {
		MBprint_array(numbers, n, stdout);
		putchar('\n');
	} while (MBnext_multiset_subset(multiset, numbers, n));

	return 0;
}
