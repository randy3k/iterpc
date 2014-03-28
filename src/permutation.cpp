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
    unsigned int i;

    if (status[0] == 0) {
        if (!MBnext_permutation((unsigned int *) x.begin(), n)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,n);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_permutation((unsigned int *) x.begin(), n)) {
                status[0] = i;
                break;
            }
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
SEXP next_k_permutations(IntegerVector x, unsigned int r, unsigned long d, IntegerVector status){
    unsigned int n = x.size();
    unsigned int i,j;

    if (status[0] == 0) {
        if (!AInext_k_permutation((unsigned int *) x.begin(), n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        for(j=0;j<r;j++) P(0,j) = x[j]+1;
        for(i=1;i<d;i++){
            if(!AInext_k_permutation((unsigned int *) x.begin(), n, r)) {
                status[0] = i;
                break;
            }
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
SEXP next_permutations_replace(IntegerVector x, unsigned int n, unsigned long d, IntegerVector status){
    unsigned int r = x.size();
    unsigned int i;
    size_t *sizes;
    sizes = (size_t*) malloc(r*sizeof(*sizes));
    for(i=0;i<r;i++) sizes[i] = n;

    if (status[0] == 0) {
        if (!MBnext_n_tuple((unsigned int *) x.begin(), r,  sizes)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_n_tuple((unsigned int *) x.begin(), r,  sizes)) {
                status[0] = i;
                break;
            }
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

