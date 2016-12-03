/*
 *  mulitcombinations.c - print the 3-multicombinations of a 4-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <multicombination.h>
#include <comb-util.h>

int main(void)
{
	unsigned int numbers[] = {0, 0, 0};
	const size_t k = sizeof(numbers) / sizeof(unsigned int);
	unsigned int n = 4;

	do {
		MBprint_array(numbers, k, stdout);
		putchar('\n');
	} while (MBnext_multicombination(numbers, n, k));

	return 0;
}
