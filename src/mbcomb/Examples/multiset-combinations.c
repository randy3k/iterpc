/*
 *  multiset-combinations.c - prints the 4-combinations of a multiset
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <multiset-combination.h>
#include <comb-util.h>

int main(void)
{
	unsigned int multiset[] = {0, 1, 1, 2, 2, 2, 3};
	const size_t n = sizeof(multiset) / sizeof(unsigned int);
	unsigned int numbers[] = {0, 1, 1, 2};
	const size_t k = sizeof(numbers) / sizeof(unsigned int);

	do {
		MBprint_array(numbers, k, stdout);
		putchar('\n');
	} while (MBnext_multiset_combination(multiset, numbers, n, k));

	return 0;
}
