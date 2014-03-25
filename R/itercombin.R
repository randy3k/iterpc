#' @name itercombin
#' @title Iterator for Permuations and Combinations
#' @docType package
#' @useDynLib itercombin
#' @import Rcpp
NULL


#' Initialize a iterator for permuations or combinations
#' @param n the length of the input sequence. If \code{x} is given, \code{n} can be missing.
#' @param r the length of the output sequence. If missing, equals to \code{n}.
#' @param x (optional) the source sequence.
#' @param type either \code{permutation} or \code{combination}. Default is \code{permutation}.
#' @param replace with/without replacement. Default is \code{FALSE}.
#' @param is.multiset the source sequence is a multiset? Default: \code{TRUE} if \code{x} contains replicates, otherwise \code{FALSE}.
#' @return a permutation/combination iterator
#' @export
iterator <- function(n=NULL, r=NULL, x=NULL, type="permutation", replace=FALSE, is.multiset = anyDuplicated(x)>0){
    if (is.null(x) & is.null(n)){
        stop("n and x are missing.")
    }
    # to immitate object behaviour
    out = new.env(parent=globalenv())
    out$replace = replace
    out$is.multiset = is.multiset
    if(replace){
        stop("with replacement is not yet implemented.")
    }else{
        if (is.multiset){
            out$multiset = sort(as.integer(as.factor(x)))-1L
            f = table(x)
            out$x = type.convert(names(f), as.is=TRUE)
            out$f = as.integer(f)
            out$n = ifelse(is.null(n), length(x), n)
            out$r = ifelse(is.null(r), out$n, as.integer(r))
        } else{
            if (!is.null(x)) out$x = x
            out$n = ifelse(is.null(n), length(out$x), n)
            out$r = ifelse(is.null(r), out$n, as.integer(r))
        }
    }
    if (type == "permutation"){
        class(out) = "piterator"
    }else if(type=="combination"){
        class(out) = "citerator"
    }else{
        stop("Invalid type.")
    }
    out
}

initElem <- function(I) UseMethod("initElem") 

#' Get all permutation/combination for a permutation iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
allElem <- function(I) UseMethod("allElem") 


#' Get the current element of the iterator 
#' @param I iterator object
#' @return current element of the iterator
#' @export
currElem <- function(I){
    if (is.null(I$curInd)) initElem(I)
    if(is.null(I$x)){
        return(I$curInd+1L)
    }else{
        return(I$x[I$curInd+1L])
    }
}

#' Get the next permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
nextElem <- function(I) UseMethod("nextElem") 

