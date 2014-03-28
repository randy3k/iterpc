#' @name iterpc
#' @title Iterator for Permutations and Combinations
#' @docType package
#' @useDynLib iterpc
#' @import Rcpp
NULL


#' Initialize a iterator for permutations or combinations
#' @param n the length of the input sequence or the input sequence.
#' @param r the length of the output sequence. If missing, equals to \code{n}.
#' @param ordered \code{TRUE} corresponses to permutation and \code{FALSE} corresponses to combinations.
#' @param replace with/without replacement. Default is \code{FALSE}.
#' @param is.multiset the source sequence is a multiset? 
#'        \code{TRUE} if \code{n} is a vector of size >1 and contains duplicates.
#' @return a permutation/combination iterator
#' @name iterpc
#' @aliases iterpc
#' @export
iterpc <- function(n, r=NULL, ordered=FALSE, replace=FALSE, 
                        is.multiset = length(n)>1 && anyDuplicated(n)>0){
    # to immitate object behaviour
    I = new.env(parent=globalenv())
    if (ordered){
        class(I) = "perm"
    }else{
        class(I) = "comb"
    }
    I$replace = replace
    I$is.multiset = is.multiset
    # status: -1, not yet initialize
    #         0, running
    #         i, number of rows of the last return incomplete result
    I$status = -1L
    if (length(n)>1){
        I$n = length(n)
        if (is.multiset){
            f = table(n)
            I$x = type.convert(names(f), as.is=TRUE)
            I$f = as.integer(f)
            I$multiset = sort(as.integer(as.factor(n)))-1L
        }else{
            I$x = n
        }
        I$r = ifelse(is.null(r), I$n, as.integer(r))
    }else{
        I$n = n
        I$r = ifelse(is.null(r), I$n, as.integer(r))
    }
    if (replace){
        I$unique_n = ifelse(is.null(I$x), I$n, length(I$x))
    }else{
        if (I$n<I$r) stop("n should be larger than or equal to r.")
    }
    I$length = getlength(I)
    I
}

#' Get all permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
getall <- function(I){
    if (I$length*I$r>.Machine$integer.max) {
        stop("The length of the iterator is too large, try using getnext(I, d).")
    }
    I$status = -1L
    out = getnext(I,I$length)
    I$status = -1L
    out
}


#' Get the current element of a iterator 
#' @param I iterator object
#' @return current element of a iterator
#' @export
getcurrent <- function(I){
    if (is.null(I$currInd)) return(NULL)
    if(is.null(I$x)){
        out = I$currInd[1:I$r]+1L
    }else{
        out = I$x[I$currInd[1:I$r]+1L]
    }
}

#' Get the next permutation(s)/combination(s) for a iterator
#' @param I a permutation(s)/combination(s) iterator
#' @param d number of permutation(s)/combination(s) wanted, default to 1
#' @param drop if \code{d} is 1, drop simplify to vector if possible, default to \code{TRUE}.
#' @return next \code{d} permutation(s)/combination(s) sequence for the iterator \code{I}
#' @export
getnext <- function(I, d=1, drop=TRUE) UseMethod("getnext") 

#' Get the length for a iterator
#' @param I a permutation(s)/combination(s) iterator
#' an integer
#' @export
getlength <- function(I) UseMethod("getlength") 
