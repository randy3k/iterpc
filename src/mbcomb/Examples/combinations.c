/*
 *  combinations.c - print the 3-combinations of a 5-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <combination.h>
#include <comb-util.h>

int main(void)
{
	unsigned int numbers[] = {0, 1, 2};
	const size_t k = sizeof(numbers) / sizeof(unsigned int);
	unsigned int n = 5;

	do {
		MBprint_array(numbers, k, stdout);
		putchar('\n');
	} while (MBnext_combination(numbers, n, k));

	return 0;
}
