#include <Rcpp.h>
extern "C" {
#include "mbcomb/Include/permutation.h"
}

using namespace Rcpp;


// [[Rcpp::export]]
unsigned int next_permutation(IntegerVector x){
    return MBnext_permutation((unsigned int *) x.begin(), x.size());;
}