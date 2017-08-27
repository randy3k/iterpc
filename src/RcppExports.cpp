// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// next_combinations
SEXP next_combinations(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_combinations(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_combinations(I, d));
    return rcpp_result_gen;
END_RCPP
}
// next_multiset_combinations
SEXP next_multiset_combinations(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_multiset_combinations(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_multiset_combinations(I, d));
    return rcpp_result_gen;
END_RCPP
}
// next_combinations_replace
SEXP next_combinations_replace(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_combinations_replace(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_combinations_replace(I, d));
    return rcpp_result_gen;
END_RCPP
}
// next_permutations
SEXP next_permutations(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_permutations(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_permutations(I, d));
    return rcpp_result_gen;
END_RCPP
}
// next_k_permutations
SEXP next_k_permutations(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_k_permutations(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_k_permutations(I, d));
    return rcpp_result_gen;
END_RCPP
}
// next_permutations_replace
SEXP next_permutations_replace(Environment I, unsigned long d);
RcppExport SEXP _iterpc_next_permutations_replace(SEXP ISEXP, SEXP dSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Environment >::type I(ISEXP);
    Rcpp::traits::input_parameter< unsigned long >::type d(dSEXP);
    rcpp_result_gen = Rcpp::wrap(next_permutations_replace(I, d));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_iterpc_next_combinations", (DL_FUNC) &_iterpc_next_combinations, 2},
    {"_iterpc_next_multiset_combinations", (DL_FUNC) &_iterpc_next_multiset_combinations, 2},
    {"_iterpc_next_combinations_replace", (DL_FUNC) &_iterpc_next_combinations_replace, 2},
    {"_iterpc_next_permutations", (DL_FUNC) &_iterpc_next_permutations, 2},
    {"_iterpc_next_k_permutations", (DL_FUNC) &_iterpc_next_k_permutations, 2},
    {"_iterpc_next_permutations_replace", (DL_FUNC) &_iterpc_next_permutations_replace, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_iterpc(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
