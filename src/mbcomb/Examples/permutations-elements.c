/*
 *  permutations-elements.c - prints the permutations of a 4-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <permutation.h>
#include <comb-util.h>

int main(void)
{
	unsigned int numbers[] = {0, 1, 2, 3};
	char *elements[] = {"a", "b", "c", "d"};
	const size_t n = sizeof(numbers) / sizeof(unsigned int);
	
	do {
		MBprint_set(numbers, n, (void*)elements, "[]", (MBprintfn)fputs, stdout);
		putchar('\n');
	} while (MBnext_permutation(numbers, n));

	return 0;
}
