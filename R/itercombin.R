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
#' @param multiset the source sequence is a multiset? Default: \code{TRUE} if \code{x} contains replicates, otherwise \code{FALSE}.
#' @return a permutation/combination iterator
#' @export
iterator <- function(n=NULL, r=NULL, x=NULL, type="permuation", replace=FALSE, multiset = anyDuplicated(x)){
    if (is.null(x) & is.null(n)){
        stop("n and x are missing.")
    }
    out = list()
    if (multiset){
        f = table(x)
        x = names(f)
        out$f = as.integer(f)
    } 
    if (is.character(x)) {
        out$x = type.convert(x)
    }else if (is.numeric(x) & all.equal(x,as.integer(x))==TRUE){
        out$x = as.integer(x)
    }
    out$n = ifelse(is.null(n), length(out$x), n)
    out$r = ifelse(is.null(r), out$n, r)
    out$replace = replace
    out$multiset = multiset
    out$curInd = 1:out$r
    if (type == "permuation"){
        class(out) = "piterator"
    }else if(type=="combination"){
        class(out) = "citerator"
    }
    out
}


#' Get the current element of the iterator 
#' @param I iterator object
#' @return current element of the iterator
#' @export
curElem <- function(I){
    if(is.null(I$x)){
        return(I$curInd)
    }else{
        return(I$x[I$curInd])
    }
}

#' Get the next permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
nextElem <- function(I, ...) UseMethod("nextElem") 

#' @method nextElem piterator
#' @name nextElem
#' @export
nextElem.piterator <- function(I){
    if (I$n == I$r & !I$replace){
        if(next_permutation(I$curInd)){
            return(curElem(I))
        }else{
            return(NULL)
        }
    }
}

#' @method nextElem citerator
#' @name nextElem
#' @export
nextElem.citerator <- function(I){
    if (I$n == I$r & !I$replace){
        if(next_permutation(I$curInd)){
            return(curElem(I))
        }else{
            return(NULL)
        }
    }
}

#' Get all permutation/combination for a permutation iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
allElem <- function(obj, ...) UseMethod("allElem") 

#' @method allElem piterator
#' @name allElem
#' @export
allElem.piterator <- function(I){
    if (I$n == I$r & !I$replace){
        P = curElem(I)
        while(next_permutation(I$curInd)){
            P = rbind(P, curElem(I))
        }
        return(P)
    }
}