/*
 *  subsets.c - prints the subsets of a 3-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <subset.h>
#include <comb-util.h>

int main(void)
{
	unsigned int ar[] = {0, 0, 0};
	const size_t n = sizeof(ar) / sizeof(unsigned int);

	do {
		MBprint_array(ar, n, stdout);
		putchar('\n');
	} while (MBnext_subset(ar, n));

	return 0;
}
