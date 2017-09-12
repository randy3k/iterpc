#include <Rcpp.h>
extern "C" {
    #include "utils/combination.h"
    #include "utils/multiset_combination.h"
    #include "utils/multicombination.h"
}

using namespace Rcpp;


// [[Rcpp::export]]
SEXP next_combinations(Environment I, unsigned long d){
    IntegerVector x = I["index"];
    unsigned int n = I["n"];
    unsigned int r = x.size();
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (as<int>(I["status"]) == 0) {
        if (!next_combination(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!next_combination(xptr, n, r)) {
                I["status"] = i;
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
SEXP next_multiset_combinations(Environment I, unsigned long d){
    IntegerVector multiset = I["multiset"];
    IntegerVector x = I["index"];
    unsigned int n = multiset.size();
    unsigned int r = x.size();
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();
    unsigned int* mptr = (unsigned int *) multiset.begin();

    if (as<int>(I["status"]) == 0) {
        if (!next_multiset_combination(mptr, xptr, n, r)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!next_multiset_combination(mptr, xptr, n, r)) {
                I["status"] = i;
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
SEXP next_combinations_replace(Environment I, unsigned long d){
    IntegerVector x = I["index"];
    unsigned int n = I["unique_n"];
    unsigned int r = x.size();
    IntegerVector status = I["status"];
    unsigned int i,j;
    unsigned int* xptr = (unsigned int *) x.begin();

    if (as<int>(I["status"]) == 0) {
        if (!next_multicombination(xptr, n, r)){
            return R_NilValue;
        }
    }else{
        I["status"] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!next_multicombination(xptr, n, r)) {
                I["status"] = i;
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
