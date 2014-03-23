/*
 *  n-tuples.c - prints the cartesian product of 3 sets
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <n-tuple.h>
#include <comb-util.h>

int main(void)
{
	unsigned int ar[] = {0, 0, 0};
	const size_t len = sizeof(ar) / sizeof(unsigned int);
	char *set0[] = {"a", "b"};
	char *set1[] = {"p", "q", "r"};
	char *set2[] = {"w", "x", "y", "z"};
	char **elements[3];
	size_t sizes[] = {sizeof(set0) / sizeof(char*),
			sizeof(set1) / sizeof(char*),
			sizeof(set2) / sizeof(char*)};
	elements[0] = set0;
    elements[1] = set1;
    elements[2] = set2;
	do {
		MBprint_array(ar, len, stdout);
		fputs(" = ", stdout);
		MBprint_n_tuple(ar, len, sizes, (void*)elements, (MBprintfn)fputs, stdout);
		putchar('\n');
	} while (MBnext_n_tuple(ar, len, sizes));

	return 0;
}
