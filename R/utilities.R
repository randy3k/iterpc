convert_z <- function(z, bigz){
    if (bigz){
        return(gmp::as.bigz(z))
    } else if (abs(z) < .Machine$integer.max) {
        return(as.integer(z))
    } else {
        stop("Integer overflow. Consider the `bigz` argument.", call. = FALSE)
    }
}

#' Calculate multinomial coefficient
#'
#' This function calculates the multinomial coefficient
#' \deqn{\frac{(\sum n_j)!}{\prod n_j!}.}{(\sum n_j)! / \prod n_j!.}
#' where \eqn{n_j}{n_j}'s are the number of multiplicities in the multiset.
#'
#' @param n a vector of group sizes
#' @param bigz use gmp's Big Interger
#' @return multinomial coefficient
#' @examples
#' # (3+1+1)!/ (3! 1! 1!) = 20
#' multichoose(c(3,1,1))
#' @export
multichoose <- function(n, bigz=FALSE){
    out <- gmp::factorialZ(sum(n))
    for (m in n) {
        out <- gmp::as.bigz(out / gmp::factorialZ(m))
    }
    convert_z(out, bigz)
}


#' Calculate the number of r-permutations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @param bigz use gmp's Big Interger
#' @return the number of r-permutations (Big Integer from gmp)
#' @examples
#' x = c("a","a","b")
#' # possible permutations of size 2 are "aa", "ab" and "ba".
#' np_multiset(table(x), 2) # = 3
#' @export
np_multiset <- function(f, r, bigz=FALSE){
    n <- sum(f)
    if (r > n){
        out <- 0
    } else if (r == 0){
        out <- 1
    } else {
        g <- gmp::factorialZ(0:min(r, max(f)))
        p <- gmp::as.bigz(rep(0L, r + 1))
        for (i in seq_along(f)){
            if (i == 1){
                p[[1:min(r + 1, f[i] + 1)]] <- gmp::factorialZ(r) / g[[1:min(r + 1, f[i] + 1)]]
            }else{
                for (j in r:1){
                    p[[j + 1]] <- sum(
                        p[[(j + 1):max(1, j + 1 - f[i])]] / g[[1:min(j + 1, f[i] + 1)]]
                        )
                }
            }
        }
        out <- p[[r + 1]]
    }
    convert_z(out, bigz)
}



#' Calculate the number of r-combinations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @param bigz use gmp's Big Interger
#' @return the number of combinations (Big Integer from gmp)
#' @examples
#' x <- c("a","a","b")
#' # possible combinations of size 2 are "aa" and "ab".
#' nc_multiset(table(x), 2) # <- 2
#' @export
nc_multiset <- function(f, r, bigz=FALSE){
    n <- sum(f)
    if (r > n){
        out <- 0
    } else if (r == 0){
        out <- 1
    } else {
        p <- gmp::as.bigz(rep(0L, r + 1))
        for (i in seq_along(f)){
            if (i == 1){
                p[[1:min(r + 1, f[i] + 1)]] <- 1
            }else{
                for (j in r:1){
                    p[[j + 1]] <- sum(p[[(j + 1):max(1, j + 1 - f[i])]])
                }
            }
        }
        out <- p[[r + 1]]
    }
    convert_z(out, bigz)
}

#' Wrap iterpc objects by iterators::iter
#' @param I the iterpc object
#' @param d number of permutation(s)/combination(s) wanted in each iteration, default to 1
#' @return a iter object compatible with iterators package
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
    iterators::iter(function() {
        out <- getnext(I, d)
        !is.null(out) || stop("StopIteration", call. = FALSE)
        out
    })
}
