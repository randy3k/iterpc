#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "util/k-permutation.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
SEXP next_permutations(IntegerVector x, long long d, unsigned long long index){
    unsigned int n = x.size();

    if (index>0) MBnext_permutation((unsigned int *) x.begin(), n); 

    if (d>1){
        IntegerMatrix P(d,n);
        P(0,_) = x;
        for(int i=1;i<d;i++){
            MBnext_permutation((unsigned int *) x.begin(), n);
            P(i,_) = x;
        }
        return P;
    }else{
        return x;
    }
}

// [[Rcpp::export]]
SEXP next_k_permutations(IntegerVector x, unsigned int r, unsigned long long d, unsigned long long index){
    unsigned int n = x.size();
    int i,j;

    if (index>0) AInext_k_permutation((unsigned int *) x.begin(), n, r); 

    if (d>1){
        IntegerMatrix P(d,r);
        for(j=0;j<r;j++) P(0,j) = x[j];
        for(i=1;i<d;i++){
            AInext_k_permutation((unsigned int *) x.begin(), n, r);
            for(j=0;j<r;j++) P(i,j) = x[j];
        }
        return P;
    }else{
        return IntegerVector(x.begin(), x.begin()+r);;
    }
}