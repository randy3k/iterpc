#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/combination.h"
    #include "mbcomb/Include/multiset-combination.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
unsigned int next_combination(IntegerVector x, unsigned int n){
    return MBnext_combination((unsigned int *) x.begin(), n, x.size());;
}

// [[Rcpp::export]]
SEXP all_combinations(SEXP x_, unsigned int n, unsigned long long d){
    IntegerVector x(clone(x_));
    unsigned int r = x.size();
    IntegerMatrix P(d,r);
    for(int i=0;i<d;i++){
        P(i,_) = x;
        MBnext_combination((unsigned int *) x.begin(), n, r);
    }
    return P;
}

// [[Rcpp::export]]
unsigned int next_multiset_combination(IntegerVector multiset, IntegerVector x){
    return MBnext_multiset_combination((unsigned int *) multiset.begin(), 
                                       (unsigned int *) x.begin(), 
                                       multiset.size(), 
                                       x.size());;
}

// [[Rcpp::export]]
SEXP all_multiset_combinations(IntegerVector multiset, SEXP x_, unsigned long long d){
    IntegerVector x(clone(x_));
    unsigned int n = multiset.size();
    unsigned int r = x.size();
    IntegerMatrix P(d,r);
    for(int i=0;i<d;i++){
        P(i,_) = x;
        MBnext_multiset_combination((unsigned int *) multiset.begin(), 
                                       (unsigned int *) x.begin(), n, r);;
    }
    return P;
}