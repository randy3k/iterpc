Efficient Iterator for Permutations and Combinations
===

Description: This package helps in 

  1. generating permutations and combinations with or without replacement; 
  2. with distinct items or non-distinct items (multiset); 
  3. calculating number of combinations or permutations in various situations. 

For the generation part, all generated sequences are in lexicographical order (AKA, dictionary order). The algorithms to generate permutations and combinations are memory efficient, only previous sequence is required to generate next sequence. These iteratively algorithms enable users to process all sequences without put all results in the memory at the same time.  The algorithms are written in C and hence are very computational efficient. 

Credit
===
I have to thanks [Martin Broadhurst](http://www.martinbroadhurst.com) and [Alistair Israel](http://alistairisrael.wordpress.com) for their algorithms. In my own opinion, [this](http://alistairisrael.wordpress.com/2009/09/22/simple-efficient-pnk-algorithm/) may be the best algorithm to generate k-permutation.