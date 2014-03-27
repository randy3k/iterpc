#' @export
getnext.comb <- function(I, d=1, drop=TRUE){
    if(I$index==I$len){
        I$index = 0
        return(NULL)
    }
    if (I$replace){
        if (I$index==0L) {
            I$currInd = rep(0L,I$r)
        }
        C = next_combinations_replace(I$currInd, I$unique_n, d, I$index)
    }else{
        if (I$index==0L) {
            if(I$is.multiset){
                # add 0L to blame lazy evaluation
                I$currInd = I$multiset[1:I$r] + 0L
            }else{
                I$currInd = (1:I$r)-1L
            }
        }
        if (I$index + d > I$len) d = I$len - I$index
        if (I$is.multiset){
            C = next_multiset_combinations(I$multiset, I$currInd, d, I$index)
        }else{
            C = next_combinations(I$currInd, I$n, d, I$index)
        }
    }
    I$index = I$index + d
    if (is.null(I$x)){
        if (drop){
            return(C)
        }else{
            return(matrix(C,nrow=1))
        }
    }else{
        if(drop && d==1){
            return(I$x[C])
        }else if(d==1){
            return(matrix(I$x[C],nrow=1))
        }else{
            t(apply(C,1,function(z) I$x[z]))
        }
    }
}

#' @export
#' @method getlength comb
getlength.comb <- function(I){
    if (I$replace){
        return(choose(I$unique_n+I$r-1,I$r))
    }else{
        if (I$is.multiset){
            return(nc.multiset(I$f, I$r))
        }else{
            return(choose(I$n,I$r))
        }
    }
}

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