/*
 *  k-permutation.c - the next k-permutation algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */


#include <combination.h>
#include <permutation.h>

#include <k-permutation.h>

unsigned int MBnext_k_permutation(unsigned int *ar, size_t n, unsigned int k)
{
	unsigned int result = MBnext_permutation(ar, k);
	if (result == 0) {
		result = MBnext_combination(ar, n, k);
	}
	return result;
}
