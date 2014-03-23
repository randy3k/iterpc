/*
 *  subset-subsets.c - prints the subsets of the subsets of a 3-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <subset-subset.h>
#include <comb-util.h>

int main(void)
{
	unsigned int ar[] = {0, 0, 1};
	const char *variables[] = {"a", "b", "c"};
	const size_t len = sizeof(ar) / sizeof(unsigned int);

	do {
		MBprint_array(ar, len, stdout);
		fputs(" = ", stdout);
		MBprint_subset_subset(ar, len, (void*)variables, (MBprintfn)puts, stdout);
		putchar('\n');
	} while (MBnext_subset_subset(ar, len));

	return 0;
}
