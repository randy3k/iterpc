/*
 *  partitions-elements.c - prints the partitions of a 4-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <partition.h>
#include <comb-util.h>

int main(void)
{
	unsigned int ar[] = {0, 0, 0, 0};
	char *elements[] = {"a", "b", "c", "d"};
	const size_t n = sizeof(ar) / sizeof(unsigned int);

	do {
		MBprint_partition(ar, n, (void*)elements, (MBprintfn)fputs, stdout);
		putchar('\n');
	} while (MBnext_partition(ar, n));

	return 0;
}
