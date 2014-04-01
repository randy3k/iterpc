Efficient Iterator for Permutations and Combinations
===

[![Build Status](https://travis-ci.org/randy3k/iterpc.svg?branch=master)](https://travis-ci.org/randy3k/iterpc)

Package Documentation: [http://rtalks.net/iterpc](http://rtalks.net/iterpc)

Github address: [https://github.com/randy3k/iterpc](https://github.com/randy3k/iterpc)


Description: This package helps in 

  1. generating (iteratively) permutations and combinations with or without replacement; 
  2. with distinct items or non-distinct items (multiset); 
  3. calculating number of combinations or permutations in various situations. 

All generated sequences are in lexicographical order (AKA, dictionary order). The algorithms to generate permutations and combinations are memory efficient, only previous sequence is required to generate next sequence. These iteratively algorithms enable users to process all sequences without putting all results in the memory at the same time.  The algorithms are written in C/C++ and hence very computational efficient. 

## Credit

I have to thanks [Martin Broadhurst](http://www.martinbroadhurst.com) and [Alistair Israel](http://alistairisrael.wordpress.com) for their algorithms. Alistair Israel has a very nice article on an algorithm to generate [k-permutation](http://alistairisrael.wordpress.com/2009/09/22/simple-efficient-pnk-algorithm/).

## Installation

If you want to install the latest development version you can use `devtools`:

```
library(devtools)
install_github("randy3k/iterpc")
```

or you can install it via CRAN

```
install.packages("iterpc")
```
