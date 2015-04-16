// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// next_combinations
SEXP next_combinations(IntegerVector x, unsigned int n, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_combinations(SEXP xSEXP, SEXP nSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_combinations(x, n, d, status));
    return __result;
END_RCPP
}
// next_multiset_combinations
SEXP next_multiset_combinations(IntegerVector multiset, IntegerVector x, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_multiset_combinations(SEXP multisetSEXP, SEXP xSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type multiset(multisetSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_multiset_combinations(multiset, x, d, status));
    return __result;
END_RCPP
}
// next_combinations_replace
SEXP next_combinations_replace(IntegerVector x, unsigned int n, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_combinations_replace(SEXP xSEXP, SEXP nSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_combinations_replace(x, n, d, status));
    return __result;
END_RCPP
}
// next_permutations
SEXP next_permutations(IntegerVector x, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_permutations(SEXP xSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_permutations(x, d, status));
    return __result;
END_RCPP
}
// next_k_permutations
SEXP next_k_permutations(IntegerVector x, unsigned int r, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_k_permutations(SEXP xSEXP, SEXP rSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type r(rSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_k_permutations(x, r, d, status));
    return __result;
END_RCPP
}
// next_permutations_replace
SEXP next_permutations_replace(IntegerVector x, unsigned int n, unsigned long d, IntegerVector status);
RcppExport SEXP iterpc_next_permutations_replace(SEXP xSEXP, SEXP nSEXP, SEXP dSEXP, SEXP statusSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type status(statusSEXP);
    __result = Rcpp::wrap(next_permutations_replace(x, n, d, status));
    return __result;
END_RCPP
}
