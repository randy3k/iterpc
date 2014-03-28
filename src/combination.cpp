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
    unsigned int i;

    if (status[0] == 0) {
        if (!MBnext_combination((unsigned int *) x.begin(), n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_combination((unsigned int *) x.begin(), n, r)) {
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
SEXP next_multiset_combinations(IntegerVector multiset, IntegerVector x, 
                                unsigned long d, IntegerVector status){
    unsigned int n = multiset.size();
    unsigned int r = x.size();
    unsigned int i;

    if (status[0] == 0) {
        if (!MBnext_multiset_combination((unsigned int *) multiset.begin(), 
                    (unsigned int *) x.begin(), n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_multiset_combination((unsigned int *) multiset.begin(), 
                    (unsigned int *) x.begin(), n, r)) {
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
SEXP next_combinations_replace(IntegerVector x, unsigned int n, 
                        unsigned long d, IntegerVector status){
    unsigned int r = x.size();
    unsigned int i;

    if (status[0] == 0) {
        if (!MBnext_multicombination((unsigned int *) x.begin(), n, r)){
            return R_NilValue;
        }
    }else{
        status[0] = 0;
    }

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(i=1;i<d;i++){
            if(!MBnext_multicombination((unsigned int *) x.begin(), n, r)) {
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
