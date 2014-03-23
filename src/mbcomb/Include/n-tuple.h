/*
 *  n-tuple.h - the next n-tuple algorithm
 *  Copyright (C) 2010 Martin Broadhurst 
 *  www.martinbroadhurst.com
 */

#ifndef N_TUPLE_H
#define N_TUPLE_H

#include <stddef.h> /* For size_t */

unsigned int MBnext_n_tuple(unsigned int *ar, size_t len, const size_t *sizes);

#endif /* N_TUPLE_H */

