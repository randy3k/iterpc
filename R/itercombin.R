#' @name itercombin
#' @title Permuations and Combinations
#' @docType package
#' @useDynLib itercombin
#' @import Rcpp
NULL

#' Set generator for permuations or combinations
#' @param type type
#' @return a generator objector
#' @export
setgen <- function(type, n=NULL, x=NULL, r=n, replace=FALSE, multiset = anyDuplicated(x)){
    if (is.null(x) & is.null(n)){
        stop("n and x are missing.")
    }
    if (is.null(n)) {n = length(x)}
    if (is.numeric(x) & all.equal(x,as.integer(x))==TRUE){
        x = as.integer(x)
    }
    if (type=="p" & !multiset){
        out = list(n=n, x=x, index=1:n, r=r)
        class(out) = "pObj"
    }
    out
}

#' Permutation generation
#'
#' Generate next permutation
#' @param x an integer-valued permutation vector
#' @return next permutation vector
#' @method next pObj
#' @aliases next
#' @export
next.pObj <- function(pObj){

}

#' Combination generation
#'
#' Generate next combination
#' @param x an integer-valued combination vector
#' @return next combination vector
#' @method next cObj
#' @aliases next
#' @export
next.cObj <- function(cObj){

}