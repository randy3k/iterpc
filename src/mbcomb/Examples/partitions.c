/*
 *  partitions.c - prints the partitions of a 4-set
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdio.h>

#include <partition.h>
#include <comb-util.h>

int main(void)
{
	unsigned int numbers[] = {0, 0, 0, 0};
	const size_t len = sizeof(numbers) / sizeof(unsigned int);

	do {
		MBprint_array(numbers, len, stdout);
		putchar('\n');
	} while (MBnext_partition(numbers, len));

	return 0;
}
