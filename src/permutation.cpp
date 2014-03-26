#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "util/k-permutation.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
unsigned int next_permutation(IntegerVector x){
    return MBnext_permutation((unsigned int *) x.begin(), x.size());;
}

// [[Rcpp::export]]
SEXP all_permutations(SEXP x_, unsigned long long d){
    IntegerVector x(clone(x_));
    unsigned int n = x.size();
    IntegerMatrix P(d,n);
    for(int i=0;i<d;i++){
        P(i,_) = x;
        MBnext_permutation((unsigned int *) x.begin(), n);
    }
    return P;
}

// [[Rcpp::export]]
unsigned int next_k_permutation(IntegerVector x, unsigned int r){
    return AInext_k_permutation((unsigned int *) x.begin(), x.size(), r);;
}

// [[Rcpp::export]]
SEXP all_k_permutations(SEXP x_, unsigned int r, unsigned long long d){
    IntegerVector x(clone(x_));
    unsigned int n = x.size();
    IntegerMatrix P(d,r);
    for(int i=0;i<d;i++){
        P(i,_) = NumericVector(x.begin(), x.begin()+r);
        AInext_k_permutation((unsigned int *) x.begin(), n, r);
    }
    return P;
}