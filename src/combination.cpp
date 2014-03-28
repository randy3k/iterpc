#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/combination.h"
    #include "mbcomb/Include/multiset-combination.h"
    #include "mbcomb/Include/multicombination.h"
}

using namespace Rcpp;


// [[Rcpp::export]]
SEXP next_combinations(IntegerVector x, unsigned int n, 
                        unsigned long d, IntegerVector status){
    unsigned int r = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (status[0] == 0) {
        if (!MBnext_combination(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_combination(xptr, n, r)) {
                status[0] = i;
                break;
            }
            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(r);
        for(j=0;j<r;j++) y[j] = xptr[j]+1;
        return y;
    }    
}


// [[Rcpp::export]]
SEXP next_multiset_combinations(IntegerVector multiset, IntegerVector x, 
                                unsigned long d, IntegerVector status){
    unsigned int n = multiset.size();
    unsigned int r = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();
    unsigned int* mptr = (unsigned int *) multiset.begin();

    if (status[0] == 0) {
        if (!MBnext_multiset_combination(mptr, xptr, n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_multiset_combination(mptr, xptr, n, r)) {
                status[0] = i;
                break;
            }

            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(r);
        for(j=0;j<r;j++) y[j] = xptr[j]+1;
        return y;
    } 
}

// [[Rcpp::export]]
SEXP next_combinations_replace(IntegerVector x, unsigned int n, 
                        unsigned long d, IntegerVector status){
    unsigned int r = x.size();
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (status[0] == 0) {
        if (!MBnext_multicombination(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_multicombination(xptr, n, r)) {
                status[0] = i;
                break;
            }
            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(r);
        for(j=0;j<r;j++) y[j] = xptr[j]+1;
        return y;
    }    
}
