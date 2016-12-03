/*
 *  multiset-combination.c - the next combination of a multiset algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#ifndef MULTISET_COMBINATION_H
#define MULTISET_COMBINATION_H

#include <stddef.h> /* For size_t */

unsigned int MBnext_multiset_combination(const unsigned int *multiset, unsigned int *ar, size_t n, unsigned int k);

#endif /* MULTISET_COMBINATION_H */
