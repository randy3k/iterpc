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
iterpc <- function(n, r=NULL, ordered=TRUE, replace=FALSE, 
                        is.multiset = length(n)>1 && anyDuplicated(n)>0){
    # to immitate object behaviour
    out = new.env(parent=globalenv())
    if (ordered){
        class(out) = "perm"
    }else{
        class(out) = "comb"
    }
    out$replace = replace
    out$is.multiset = is.multiset
    out$index = 0L
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
    if (replace){
        out$unique_n = ifelse(is.null(out$x), out$n, length(out$x))
    }
    out$len = getlength(out)
    out
}

#' Get all permutation/combination for a iterator
#' @param I a permutation/combination iterator
#' @return next permutation/combination sequence for the iterator \code{I}
#' @export
getall <- function(I){
    I$index = 0L
    out = getnext(I,I$len)
    I$index = 0L
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

#' Get the current index of a iterator 
#' @param I iterator object
#' @return current index of a iterator
#' @export
getindex <- function(I){
    I$index
}

#' Get the next permutation(s)/combination(s) for a iterator
#' @param I a permutation(s)/combination(s) iterator
#' @param d number of permutation(s)/combination(s) wanted, default to 1
#' @param drop simplify to vector if possible, default to \code{TRUE}.
#' @return next \code{d} permutation(s)/combination(s) sequence for the iterator \code{I}
#' @export
getnext <- function(I, d=1, drop=TRUE) UseMethod("getnext") 

#' Get the length for a iterator
#' @param I a permutation(s)/combination(s) iterator
#' an integer
#' @export
getlength <- function(I) UseMethod("getlength") 
