/*
 *  comb-util.c - combinatorial utility functions
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#include <comb-util.h>

void MBprint_array(const unsigned int *ar, size_t len, FILE *fptr)
{
	unsigned int i;
	fputc('[', fptr);
	for (i = 0; i < len; i++) {
		fprintf(fptr, "%d", ar[i]);
		if (i < len - 1) {
			fputs(", ", fptr);
		}
	}
	fputc(']', fptr);
}


void MBprint_set(const unsigned int *ar, size_t len, const void **elements, 
		const char *brackets, MBprintfn print, FILE *fptr)
{
	unsigned int i;
	fputc(brackets[0], fptr);
	for (i = 0; i < len; i++) {
		print(elements[ar[i]], fptr);
		if (i < len - 1) {
			fputs(", ", fptr);
		}
	}
	fputc(brackets[1], fptr); 
}

static unsigned int MBarray_count(const unsigned int *ar, size_t len,
	   	unsigned int value)
{
	unsigned int count = 0;
	unsigned int i;
	for (i = 0; i < len; i++) {
		if (ar[i] == value) {
			count++;
		}
	}
	return count;
}

static unsigned int MBarray_max(const unsigned int *ar, size_t len)
{
	unsigned int max = 0;
	unsigned int i;
	for (i = 0; i < len; i++) {
		if (ar[i] > max) {
			max = ar[i];
		}
	}
	return max;
}

void MBprint_partition(const unsigned int *ar, size_t len, 
		const void **elements, MBprintfn print, FILE *fptr)
{
	/* Find the number of sets in the partition  */
	const unsigned int sets = MBarray_max(ar, len) + 1;
	unsigned int s;
	fputc('{', fptr);
	for (s = 0; s < sets; s++) {
		unsigned int e;
		unsigned int added = 0;
		/* Find the size of this set */
		const unsigned int size = MBarray_count(ar, len, s);
		fputc('{', fptr);
		for (e = 0; e < len; e++) {
			/* Is this element in this set? */
			if (ar[e] == s) {
				print(elements[e], fptr);
				added++;
				if (added < size) {
					fputs(", ", fptr);
				}
			}
		}
		fputc('}', fptr);
		if (s < sets - 1) {
			fputs(", ", fptr);
		}
	}
	fputc('}', fptr);
}

void MBprint_subset(const unsigned int *ar, size_t len, const void **elements, 
		MBprintfn print, FILE *fptr)
{
	unsigned int i, started = 0;
	fputc('{', fptr);
	for (i = 0; i < len; i++) {
		if (ar[i]) {
			if (started) {
				fputs(", ", fptr);
			}
			print(elements[i], fptr);
			started = 1;
		}
	}
	fputc('}', fptr); 
}
		
void MBprint_multiset_subset(const unsigned int *ar, size_t len, 
		const void **elements, MBprintfn print, FILE *fptr)
{
	unsigned int i, started = 0;
	fputc('[', fptr);
	for (i = 0; i < len; i++) {
		unsigned int j;
		for (j = 0; j < ar[i]; j++) {
			if (started) {
				fputs(", ", fptr);
			}
			print(elements[i], fptr);
			started = 1;
		}
	}
	fputc(']', fptr); 
}

void MBprint_subset_subset(const unsigned int *ar, size_t len, 
		const void **variables, MBprintfn print, FILE *fptr)
{
	unsigned int v;
	unsigned int started;
	/* Print the parent set */
	started = 0;
	fputc('{', fptr);
	for (v = 0; v < len; v++) {
		if (ar[v]) {
			if (started) {
				fputs(", ", fptr);
			}
			fputs(variables[v], fptr);
			started = 1;
		}
	}
	fputs("} ", fptr);
	/* Print the subset */
	fputc('{', fptr);
	started = 0;
	for (v = 0; v < len; v++) {
		if (ar[v] == 1) {
			if (started) {
				fputs(", ", fptr);
			}
			fputs(variables[v], fptr);
			started = 1;
		}
	}
	fputs("} ", fptr);
}

void MBprint_n_tuple(const unsigned int *ar, size_t len,
		const size_t *sizes, const void ***variables,
		MBprintfn print, FILE *fptr)
{
	unsigned int s;

	putchar('<');
	for (s = 0; s < len; s++) {
		print(variables[s][ar[s]], fptr);
		if (s < len - 1) {
			fputs(", ", fptr);
		}
	}
	putchar('>');
}
