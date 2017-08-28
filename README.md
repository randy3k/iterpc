Efficient Iterators for Permutations and Combinations
===

[![Build Status](https://travis-ci.org/randy3k/iterpc.svg?branch=master)](https://travis-ci.org/randy3k/iterpc)

[![](http://cranlogs.r-pkg.org/badges/grand-total/iterpc)](https://cran.r-project.org/package=iterpc)

Latest Documentation: [http://randy3k.github.io/iterpc](https://randy3k.github.io/iterpc)

Github: [https://github.com/randy3k/iterpc](https://github.com/randy3k/iterpc)


A collection of iterators for generating permutations and combinations with or
without replacement; with distinct items or non-distinct items (multiset).
The generated sequences are in lexicographical order (dictionary order). The
algorithms to generate permutations and combinations are memory efficient. These
iterative algorithms enable users to process all sequences without putting all
results in the memory at the same time. The algorithms are written in C/C++ for
faster performances.

## Credit

Thank [Martin Broadhurst](http://www.martinbroadhurst.com) and [Alistair Israel](http://alistairisrael.wordpress.com) for their algorithms. Alistair Israel has a very nice article on an algorithm to generate [k-permutation](http://alistairisrael.wordpress.com/2009/09/22/simple-efficient-pnk-algorithm/).

## Installation

If you want to install the latest development version, you can use `devtools`:

```
devtools::install_github("randy3k/iterpc")
```

or you can install the stable version via CRAN

```
install.packages("iterpc")
```
