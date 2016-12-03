/*
 *  comb-util.h - combinatorial utility functions
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#ifndef COMB_UTIL_H
#define COMB_UTIL_H

#include <stddef.h> /* For size_t */

#include <mbcommon.h>

void MBprint_array(const unsigned int *ar, size_t len, FILE *fptr);
void MBprint_set(const unsigned int *ar, size_t len, const void **elements, 
		const char *brackets, MBprintfn print, FILE *fptr);
void MBprint_subset(const unsigned int *ar, size_t len, const void **elements,
	   	MBprintfn print, FILE *fptr);
void MBprint_partition(const unsigned int *ar, size_t len, 
		const void **elements, MBprintfn print, FILE *fptr);
void MBprint_multiset_subset(const unsigned int *ar, size_t len, 
		const void **elements, MBprintfn print, FILE *fptr);
void MBprint_subset_subset(const unsigned int *ar, size_t lenn, 
		const void **elements, MBprintfn print, FILE *fptr);
void MBprint_n_tuple(const unsigned int *ar, size_t len,
		const size_t *sizes, const void ***variables,
		MBprintfn print, FILE *fptr);

#endif /* COMB_UTIL_H */
