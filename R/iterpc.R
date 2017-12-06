#' @name iterpc
#' @title Efficient Iterator for Permutations and Combinations
#' @docType package
#' @useDynLib iterpc
#' @import Rcpp
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
    I$replace <- replace

    I$is.multiset <- class(n) == "table" || length(n) > 1
    # status: -1, not yet initialize
    #         0, running
    #         i, number of rows of the last returned incomplete result when d > 1
    # make sure I$status get a new memmory address in bytecode complier
    I$status <- -1L

    if (I$is.multiset){
        I$n <- n[n > 0]
        I$f <- as.integer(I$n)
        I$multiset <- rep(0:(length(I$f) - 1L), I$n)
        I$n <- sum(I$n)
    }else{
        I$n <- n
    }
    if (I$n < 1) stop("n should be positive.")

    if (is.null(r)) {
        I$r <- I$n
    } else {
        I$r <- as.integer(r)
        if (I$r < 1) stop("r should be positive.")
    }
    if (!is.null(labels)) {
        I$labels <- labels[n > 0]
    }else if (class(n) == "table") {
        I$labels <- type.convert(names(n[n > 0]))
    }
    if (replace){
        if (is.null(I$f)) {
            I$unique_n <- I$n
        } else {
            I$unique_n <- length(I$f)
        }
    }else{
        if (sum(I$n) < I$r) stop("n should be larger than or equal to r.")
    }

    return(I)
}

#' Get all permutations/combinations for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
getall <- function(I){
    len <- getlength(I, bigz = TRUE)
    if (len * I$r > .Machine$integer.max) {
        stop("The output is too long, consider `getnext(I, d)`.")
    }
    len <- as.integer(len)
    I$status <- -1L
    out <- getnext(I, len, drop = FALSE)
    I$status <- -1L
    out
}


#' Get the current element of a iterator
#' @param I a permutation/combination iterator
#' @return current element of a iterator
#' @export
getcurrent <- function(I){
    if (is.null(I$index)) return(NULL)
    if (is.null(I$x)){
        out <- I$index[1:I$r] + 1L
    }else{
        out <- I$x[I$index[1:I$r] + 1L]
    }
    if (is.null(I$labels)){
        return(out)
    }else{
        return(I$labels[out])
    }
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
