#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "mbcomb/Include/combination.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
unsigned int next_permutation(IntegerVector x){
    return MBnext_permutation((unsigned int *) x.begin(), x.size());;
}

// [[Rcpp::export]]
unsigned int next_combination(IntegerVector x, unsigned int n){
    return MBnext_combination((unsigned int *) x.begin(), n, x.size());;
}