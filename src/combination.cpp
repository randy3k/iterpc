#include <Rcpp.h>
extern "C" {
    #include "mbcomb/Include/combination.h"
    #include "mbcomb/Include/multiset-combination.h"
    #include "mbcomb/Include/multicombination.h"
}

using namespace Rcpp;


// [[Rcpp::export]]
SEXP next_combinations(IntegerVector x, unsigned int n, 
                        unsigned long long d, unsigned long long index){
    unsigned int r = x.size();
    if (index>0) MBnext_combination((unsigned int *) x.begin(), n, r);

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(int i=1;i<d;i++){
            MBnext_combination((unsigned int *) x.begin(), n, r);
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
                                unsigned long long d, unsigned long long index){
    unsigned int n = multiset.size();
    unsigned int r = x.size();
    if (index>0) MBnext_combination((unsigned int *) x.begin(), n, r);

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(int i=1;i<d;i++){
            MBnext_multiset_combination((unsigned int *) multiset.begin(), 
                                           (unsigned int *) x.begin(), n, r);;
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
                        unsigned long long d, unsigned long long index){
    unsigned int r = x.size();
    if (index>0) MBnext_multicombination((unsigned int *) x.begin(), n, r);

    if (d>1){
        IntegerMatrix P(d,r);
        P(0,_) = x+1;
        for(int i=1;i<d;i++){
            MBnext_multicombination((unsigned int *) x.begin(), n, r);
            P(i,_) = x+1;
        }
        return P;
    }else{
        IntegerVector y(clone(x));
        y = y + 1;
        return y;
    }    
}