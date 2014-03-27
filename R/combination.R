#' Calcuate the number of combinations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @return the number of combinations
#' @examples
#' x = c("a","a","b")
#' # possible combinations of size 2 are "aa" and "ab".
#' np.multiset(table(x), 2) # = 2
#' @export
#' @import polynom
nc.multiset <- function(f, r){
    p <- polynomial(1)
    for(i in f){
        p <- p * polynomial(rep.int(1, i + 1))
        p <- polynomial(p[1:min(length(p),r+1)])
    }
    return(p[r+1])
}

#' @export
getNext.comb <- function(I){
    if (I$replace){

    }else{
        if (I$is.multiset){
            if (is.null(I$currInd)) {
                I$currInd = sort(I$multiset)[1:I$r]
                return(getCurrent(I))
            }else if(next_multiset_combination(I$multiset, I$currInd)){
                return(getCurrent(I))
            }else{
                I$currInd = NULL
                return(NULL)
            }
        }else{
            if (is.null(I$currInd)) {
                I$currInd = (1:I$r)-1L
                return(getCurrent(I))
            }else if(next_combination(I$currInd, I$n)){
                return(getCurrent(I))
            }else{
                I$currInd = NULL
                return(NULL)
            }
        }
    }
}

#' @export
getAll.comb <- function(I){
    if (I$replace){

    }else{
        if (I$is.multiset){
            C = all_multiset_combinations(I$multiset, sort(I$multiset)[1:I$r], length(I))
            if (is.null(I$x)){
                return(C+1)
            }else{
                return(t(apply(C,1,function(z) I$x[z+1])))
            }
        }else{
            C = all_combinations((1:I$r)-1L, I$n, length(I))
            if (is.null(I$x)){
                return(C+1)
            }else{
                return(t(apply(C,1,function(z) I$x[z+1])))
            }
        }
    }
}

#' @export
#' @method length comb
length.comb <- function(x){
    if (x$replace){

    }else{
        if (x$is.multiset){
            return(nc.multiset(x$f, x$r))
        }else{
            return(choose(x$n,x$r))
        }
    }
}