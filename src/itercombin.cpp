#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "mbcomb/Include/combination.h"
}

using namespace Rcpp;

//' @export
// [[Rcpp::export]]
unsigned int next_permutation(IntegerVector x){
    return MBnext_permutation((unsigned int *) x.begin(), x.size());;
}

//' @export
// [[Rcpp::export]]
unsigned int next_combination(IntegerVector x, unsigned int r){
    return MBnext_combination((unsigned int *) x.begin(), x.size(), r);;
}