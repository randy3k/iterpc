#' @name iterpc
#' @title Efficient Iterator for Permutations and Combinations
#' @docType package
NULL


#' Initialize a iterator for permutations or combinations
#' @param n the length of the input sequence or a vector of frequencies for a multiset.
#' @param r the length of the output sequence. If missing, equals to \code{sum(n)}.
#' @param labels if \code{missing}, natural numbers are used unless \code{n} is a table object.
#'              In that case, the names of \code{n} are used.
#' @param ordered \code{TRUE} corresponds to permutation and \code{FALSE} corresponds to combinations.
#' @param replace with/without replacement. Default is \code{FALSE}.
#' @return a permutation/combination iterator
#' @name iterpc
#' @aliases iterpc
#' @importFrom utils type.convert
#' @importFrom arrangements icombinations ipermutations
#' @export
#' @examples
#' #1) all combinations of drawing 2 items from {1, 2, 3}
#' I <- iterpc(5, 2)
#' getall(I)
#'
#' #2) continuing 1), get combination by combination
#' I <- iterpc(5, 2)
#' getnext(I) # return 1,2
#' getnext(I) # return 1,3
#' getnext(I, 2) # return next 2 results
#'
#' #3) 3) all permutations of {1, 2, 3} and use of labels
#' I <- iterpc(3, labels=c("a", "b", "c"), ordered=TRUE)
#' getall(I)
#'
#' #4) permutations of multiset and
#' I <- iterpc(c(2, 1, 1), labels=c("a", "b", "c"), ordered=TRUE)
#' getall(I)
#'
#' #5) combinations with replacement and the use of table as input
#' x <- c("a","a","b","c")
#' I <- iterpc(table(x), 3, replace=TRUE)
#' getall(I)
iterpc <- function(n, r=NULL, labels=NULL, ordered=FALSE, replace=FALSE){
    # to immitate object behaviour
    I <- new.env(parent = globalenv())
    if (ordered){
        class(I) <- "perm"
    }else{
        class(I) <- "comb"
    }
    is.multiset <- class(n) == "table" || length(n) > 1

    if (is.multiset){
        freq <- as.integer(n)
        n <- sum(n)
    } else {
        freq <- NULL
    }

    if (is.null(r)) {
        r <- n
    }

    if (replace){
        if (is.null(freq)) {
            unique_n <- n
        } else {
            unique_n <- length(freq)
        }
    } else {
        unique_n <- NULL
    }

    if (replace){
        if (ordered){
            I$object <- arrangements::Permutations$new(
                unique_n, r, labels, replace = replace)
        } else {
            I$object <- arrangements::Combinations$new(
                unique_n, r, labels, replace = replace)
        }
    } else {
        if (!is.null(freq)) {
            n_ <- length(freq)
        } else {
            n_ <- n
        }

        if (ordered) {
            I$object <- arrangements::Permutations$new(
                n_, r, labels, freq = freq, replace = replace)
        } else {
            I$object <- arrangements::Combinations$new(
                n_, r, labels, freq = freq, replace = replace)
        }
    }

    I$n <- n
    I$r <- r
    I$f <- freq[freq > 0]
    I$replace <- replace
    I$is.multiset <- is.multiset
    I$unique_n <- unique_n

    I
}

#' Get all permutations/combinations for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
getall <- function(I){
    I$object$reset()
    I$object$collect()
}


#' Get the current element of a iterator
#' @param I a permutation/combination iterator
#' @return current element of a iterator
#' @export
getcurrent <- function(I){
    I$last
}

#' Get the next permutation(s)/combination(s) for a iterator
#' @param I a permutation/combination iterator
#' @param d number of permutation(s)/combination(s) wanted, default to 1
#' @param drop if \code{d} is 1, drop simplify to vector if possible, default to \code{TRUE}.
#' @return next \code{d} permutation(s)/combination(s) sequence for the iterator \code{I}
#' @export
getnext <- function(I, d=1, drop=TRUE) UseMethod("getnext")

#' Get the length for a iterator
#' @param I a permutations/combinations iterator
#' @param bigz use gmp's Big Interger
#' @return an integer
#' @export
getlength <- function(I, bigz=FALSE) UseMethod("getlength")
