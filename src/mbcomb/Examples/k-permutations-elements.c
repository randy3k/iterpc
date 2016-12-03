/*
 *  k-permutations-elements.c - print the 3-permutations of a 4-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <k-permutation.h>
#include <comb-util.h>

int main(void)
{
	unsigned int numbers[] = {0, 1, 2};
	char *elements[] = {"a", "b", "c", "d"};
	const size_t k = sizeof(numbers) / sizeof(unsigned int);
	const size_t n = sizeof(elements) / sizeof(const char*);

	do {
		MBprint_set(numbers, k, (void*)elements, "[]", (MBprintfn)fputs, stdout);
		putchar('\n');
	} while (MBnext_k_permutation(numbers, n, k));

	return 0;
}
