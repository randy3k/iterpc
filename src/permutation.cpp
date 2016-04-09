#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/permutation.h"
    #include "mbcomb/Include//n-tuple.h"
    #include "utils/k-permutation.h"
}

using namespace Rcpp;

// [[Rcpp::export]]
SEXP next_permutations(Environment I, unsigned long d){
    IntegerVector x = I["index"];
    unsigned int n = x.size();
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (as<int>(I["status"]) == 0) {
        if (!MBnext_permutation(xptr, n)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,n);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_permutation(xptr, n)) {
                I["status"] = i;
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
SEXP next_k_permutations(Environment I, unsigned long d){
    IntegerVector x = I["index"];
    unsigned int n = x.size();
    unsigned int r = I["r"];
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (as<int>(I["status"]) == 0) {
        if (!AInext_k_permutation(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        for(j=0;j<r;j++) P(0,j) = xptr[j]+1;
        for(i=1;i<d;i++){
            if(!AInext_k_permutation(xptr, n, r)) {
                I["status"] = i;
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
SEXP next_permutations_replace(Environment I, unsigned long d){
    IntegerVector x = I["index"];
    unsigned int n = I["unique_n"];
    unsigned int r = x.size();
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    size_t *sizes;
    sizes = (size_t*) malloc(r*sizeof(*sizes));
    for(i=0;i<r;i++) sizes[i] = n;

    if (as<int>(I["status"]) == 0) {
        if (!MBnext_n_tuple(xptr, r,  sizes)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_n_tuple(xptr, r,  sizes)) {
                I["status"] = i;
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
