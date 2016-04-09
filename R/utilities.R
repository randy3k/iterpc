#' Calculate multinomial coefficient
#'
#' This function calculates the multinomial coefficient
#' \deqn{\frac{(\sum n_j)!}{\prod n_j!}.}{(\sum n_j)! / \prod n_j!.}
#' where \eqn{n_j}{n_j}'s are the number of multiplicities in the multiset.
#'
#' The result is not reliable if the retunred value is too large (around 2^53) due to limition of integers.
#' @param n a vector of group sizes
#' @return multinomial coefficient
#' @examples
#' # (3+1+1)!/ (3! 1! 1!) = 20
#' multichoose(c(3,1,1))
#' @export
#' @import gmp
multichoose <- function(n){
    out <- factorialZ(sum(n)) / prod(factorialZ(n))
    if (out > .Machine$integer.max){
        stop("Overflow error!")
    }
    as.integer(out)
}


#' Calculate the number of r-permutations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @return the number of r-permutations
#' @examples
#' x = c("a","a","b")
#' # possible permutations of size 2 are "aa", "ab" and "ba".
#' np_multiset(table(x), 2) # = 3
#' @export
#' @import gmp
np_multiset <- function(f, r){
    n <- sum(f)
    if (r > n){
        return(0)
    } else if (r == 0){
        return(1)
    } else {
        g <- factorialZ(0:min(r, max(f)))
        p <- as.bigz(rep(0L, r + 1))
        for (i in seq_along(f)){
            if (i == 1){
                p[1:min(r + 1, f[i] + 1)] <- factorialZ(r) / g[1:min(r + 1, f[i] + 1)]
            }else{
                for (j in r:1){
                    p[j + 1] <- sum(
                        p[(j + 1):max(1, j + 1 - f[i])] / g[1:min(j + 1, f[i] + 1)]
                        )
                }
            }
        }
    }
    out <- p[r + 1]
    if (out > .Machine$integer.max){
        stop("Overflow error!")
    }
    as.integer(out)
}



#' Calculate the number of r-combinations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @return the number of combinations
#' @examples
#' x <- c("a","a","b")
#' # possible combinations of size 2 are "aa" and "ab".
#' nc_multiset(table(x), 2) # <- 2
#' @export
#' @import gmp
nc_multiset <- function(f, r){
    n <- sum(f)
    if (r > n){
        return(0)
    } else if (r == 0){
        return(1)
    } else {
        p <- as.bigz(rep(0L, r + 1))
        for (i in seq_along(f)){
            if (i == 1){
                p[1:min(r + 1, f[i] + 1)] <- 1
            }else{
                for (j in r:1){
                    p[j + 1] <- sum(p[(j + 1):max(1, j + 1 - f[i])])
                }
            }
        }
    }
    out <- p[r + 1]
    if (out > .Machine$integer.max){
        stop("Overflow error!")
    }
    as.integer(out)
}

#' Wrap iterpc objects by iterators::iter
#' @param I the iterpc object
#' @param d number of permutation(s)/combination(s) wanted in each iteration, default to 1
#' @return a iter object compatible with iterators package
#' @import iterators
#' @examples
#' library(iterators)
#' I <- iterpc(5, 2)
#' it <- iter_wrapper(I)
#' nextElem(it)
#' nextElem(it)
#'
#' library(foreach)
#' I <- iterpc(5, 2)
#' it <- iter_wrapper(I)
#' foreach(x=it, .combine=c) %do% { sum(x) }
#' @export
iter_wrapper <- function(I, d=1){
    iter(function() {
        out <- getnext(I, d)
        !is.null(out) || stop("StopIteration", call. = FALSE)
        out
    })
}
