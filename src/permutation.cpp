#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "mbcomb/Include//n-tuple.h"
    #include "util/k-permutation.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
SEXP next_permutations(IntegerVector x, unsigned long d, unsigned long index){
    unsigned int n = x.size();
    unsigned int i;

    if (index>0) MBnext_permutation((unsigned int *) x.begin(), n); 

    if (d>1){
        IntegerMatrix P(d,n);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            MBnext_permutation((unsigned int *) x.begin(), n);
            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(clone(x));
        y = y + 1;
        return y;
    }
}

// [[Rcpp::export]]
SEXP next_k_permutations(IntegerVector x, unsigned int r, unsigned long d, unsigned long index){
    unsigned int n = x.size();
    unsigned int i,j;

    if (index>0) AInext_k_permutation((unsigned int *) x.begin(), n, r); 

    if (d>1){
        IntegerMatrix P(d,r);
        for(j=0;j<r;j++) P(0,j) = x[j]+1;
        for(i=1;i<d;i++){
            AInext_k_permutation((unsigned int *) x.begin(), n, r);
            for(j=0;j<r;j++) P(i,j) = x[j]+1;
        }
        return P;
    }else{
        IntegerVector y(clone(IntegerVector(x.begin(), x.begin()+r)));
        y = y + 1;
        return y;
    }
}

// [[Rcpp::export]]
SEXP next_permutations_replace(IntegerVector x, unsigned int n, unsigned long d, unsigned long index){
    unsigned int r = x.size();
    unsigned int i;
    size_t *sizes;
    sizes = (size_t*) malloc(r*sizeof(*sizes));
    for(i=0;i<r;i++) sizes[i] = n;

    if (index>0) MBnext_n_tuple((unsigned int *) x.begin(), r,  sizes); 

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            MBnext_n_tuple((unsigned int *) x.begin(), r,  sizes); 
            P(i,_) = x+1;
        }
        free(sizes);
        return P;
    }else{
        free(sizes);
        IntegerVector y(clone(x));
        y = y + 1;
        return y;
    }
}

