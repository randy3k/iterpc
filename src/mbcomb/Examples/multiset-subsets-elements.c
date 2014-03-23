/*
 *  multiset-subsets-elements.c - prints the subsets of a multiset
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
	char *elements[] = {"a", "b", "c"};
	unsigned int numbers[] = {0, 0, 0};

	do {
		MBprint_multiset_subset(numbers, n, (void*)elements, (MBprintfn)fputs, stdout);
		putchar('\n');
	} while (MBnext_multiset_subset(multiset, numbers, n));

	return 0;
}
