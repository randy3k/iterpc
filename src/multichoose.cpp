#include <Rcpp.h>
extern "C" {
    #include "util/count.h"
}

using namespace Rcpp;

//' Calculate mulinomial coefficient
//' @param n a vector of group sizes
//' @return multinomial coefficient
//' @details This function calculate the multinomial coefficient \deqn{\frac{(\sum n_j)!}{\prod n_j!}.}{(\sum n_j)! / \prod n_j!.}
//' 
//' Overflow error will be thrown if the return value is larger than the maximum limit of an unsigned long long variable.
//' @examples
//' # (3+1+1)!/ (3! 1! 1!) = 20
//' multichoose(c(3,1,1))
//' @export
// [[Rcpp::export]]
unsigned long long multichoose(SEXP n){
    IntegerVector x(clone(n));
    unsigned long long C;
    C = multinomial((unsigned int *) x.begin(), (unsigned int) x.size());
    if (C==0) stop("Overflow Error!");
    return C;
}
