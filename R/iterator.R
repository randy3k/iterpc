#' @name itercombin
#' @title Iterator for Permuations and Combinations
#' @docType package
#' @useDynLib itercombin
#' @import Rcpp
NULL


#' Initialize a iterator for permuations or combinations
#' @param n the length of the input sequence or the input sequence.
#' @param r the length of the output sequence. If missing, equals to \code{n}.
#' @param type either \code{permutation} or \code{combination}. Default is \code{permutation}.
#' @param replace with/without replacement. Default is \code{FALSE}.
#' @param is.multiset the source sequence is a multiset? 
#'        \code{TRUE} if \code{n} is a vector of size >1 and contains duplicates.
#' @return a permutation/combination iterator
#' @export
iterator <- function(n, r=NULL, type="permutation", replace=FALSE, 
                        is.multiset = length(n)>1 && anyDuplicated(n)>0){
    # to immitate object behaviour
    out = new.env(parent=globalenv())
    out$replace = replace
    out$is.multiset = is.multiset
    if(replace){
        stop("with replacement is not yet implemented.")
    }else{
        if (length(n)>1){
            out$n = length(n)
            if (is.multiset){
                f = table(n)
                out$x = type.convert(names(f), as.is=TRUE)
                out$f = as.integer(f)
                out$multiset = sort(as.integer(as.factor(n)))-1L
            }else{
                out$x = n
            }
            out$r = ifelse(is.null(r), out$n, as.integer(r))
        }else{
            out$n = n
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

#' Get all permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
allElem <- function(I) UseMethod("allElem") 


#' Get the current element of a iterator 
#' @param I iterator object
#' @return current element of a iterator
#' @export
currElem <- function(I){
    if (is.null(I$currInd)) nextElem(I)
    if(is.null(I$x)){
        return(I$currInd[1:I$r]+1L)
    }else{
        return(I$x[I$currInd[1:I$r]+1L])
    }
}

#' Get the next permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
nextElem <- function(I) UseMethod("nextElem") 

