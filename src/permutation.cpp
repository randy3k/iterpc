#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "mbcomb/Include//n-tuple.h"
    #include "utils/k-permutation.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
SEXP next_permutations(IntegerVector x, unsigned long d, IntegerVector status){
    unsigned int n = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (status[0] == 0) {
        if (!MBnext_permutation(xptr, n)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,n);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_permutation(xptr, n)) {
                status[0] = i;
                break;
            }
            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(n);
        for(j=0;j<n;j++) y[j] = xptr[j]+1;
        return y;
    }
}

// [[Rcpp::export]]
SEXP next_k_permutations(IntegerVector x, unsigned int r, unsigned long d, IntegerVector status){
    unsigned int n = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (status[0] == 0) {
        if (!AInext_k_permutation(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        for(j=0;j<r;j++) P(0,j) = xptr[j]+1;
        for(i=1;i<d;i++){
            if(!AInext_k_permutation(xptr, n, r)) {
                status[0] = i;
                break;
            }
            for(j=0;j<r;j++) P(i,j) = xptr[j]+1;
        }
        return P;
    }else{
        IntegerVector y(r);
        for(j=0;j<r;j++) y[j] = xptr[j]+1;
        return y;
    }
}

// [[Rcpp::export]]
SEXP next_permutations_replace(IntegerVector x, unsigned int n, unsigned long d, IntegerVector status){
    unsigned int r = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    size_t *sizes;
    sizes = (size_t*) malloc(r*sizeof(*sizes));
    for(i=0;i<r;i++) sizes[i] = n;

    if (status[0] == 0) {
        if (!MBnext_n_tuple(xptr, r,  sizes)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_n_tuple(xptr, r,  sizes)) {
                status[0] = i;
                break;
            }
            P(i,_) = x+1;
        }
        free(sizes);
        return P;
    }else{
        free(sizes);
        IntegerVector y(r);
        for(j=0;j<r;j++) y[j] = xptr[j]+1;
        return y;
    }
}

