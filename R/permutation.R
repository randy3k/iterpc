#' @export
getNext.perm <- function(I, d=1, drop=TRUE){
    if(I$index==I$len){
        I$index = 0
        return(NULL)
    }
    if (I$replace){
        if (I$index==0L) {
            I$currInd = rep(0L,I$r)
        }
        P = next_permutations_replace(I$currInd, I$unique_n, d, I$index)
    }else{
        if (I$index==0L) {
            if(I$is.multiset){
                # add 0L to blame lazy evaluation
                I$currInd = I$multiset + 0L
            }else{
                I$currInd = (1:I$n)-1L
            }
        }
        if (I$index + d > I$len) d = I$len - I$index
        if (I$n == I$r){
            P = next_permutations(I$currInd, d, I$index)
        }else{
            P = next_k_permutations(I$currInd, I$r, d, I$index)
        }
    }
    I$index = I$index + d
    if (is.null(I$x)){
        if (drop){
            return(P)
        }else{
            return(matrix(P,nrow=1))
        }
    }else{
        if(drop && d==1){
            return(I$x[P])
        }else if(d==1){
            return(matrix(I$x[P],nrow=1))
        }else{
            t(apply(P,1,function(z) I$x[z]))
        }
    }
}


#' @export
#' @method len perm
len.perm <- function(I){
    if (I$replace){
        return(I$unique_n^I$r)
    }else{
        if (I$n == I$r){
            if (I$is.multiset){
                return(multichoose(I$f))
            }else{
                return(factorial(I$n))
            }
        }else{
            if (I$is.multiset){
                return(np.multiset(I$f, I$r))
            }else{
                return(prod(I$n:(I$n-I$r+1)))
            }
        }
    }
}

#' Calcuate the number of r-permutations of a multiset
#' @param f the frequencies of the mutliset
#' @param r the number of object drawn from the multiset
#' @return the number of r-permutations
#' @examples
#' x = c("a","a","b")
#' # possible permutations of size 2 are "aa", "ab" and "ba".
#' np.multiset(table(x), 2) # = 3
#' @export
#' @import polynom
np.multiset <- function(f, r){
    p <- polynomial(1)
    alpha = lgamma(r+1)/length(f)
    for(i in f){
        j = pmin(i, r)
        p <- p * polynomial(exp(c(alpha,alpha-lgamma((1:j)+1))))
        p <- polynomial(p[1:min(length(p),r+1)])
    }
    return(round(p[r+1]))
}