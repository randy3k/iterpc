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

# np.multiset <- function(f, r){
#     p <- polynomial(1)
#     for(i in f){
#         p <- p * polynomial(c(1,1/factorial(1:pmin(i,r))))
#         p <- polynomial(p[1:min(length(p),r+1)])
#     }
#     return(round(p[r+1]*factorial(r)))
# }

#' @export
allElem.piterator <- function(I){
    if (I$replace){

    }else{
        if (I$n == I$r){
            if (I$is.multiset){
                P = all_permutations(I$multiset, length(I))
            }else{
                P = all_permutations((1:I$n)-1L, length(I))
            }
            if (is.null(I$x)){
                return(P+1)
            }else{
                return(t(apply(P,1,function(z) I$x[z+1])))
            }
        }else{
            if (I$is.multiset){
                P = all_k_permutations(I$multiset, I$r, length(I))
            }else{
                P = all_k_permutations((1:I$n)-1L, I$r, length(I))
            }
            if (is.null(I$x)){
                return(P+1)
            }else{
                return(t(apply(P,1,function(z) I$x[z+1])))
            }
        }
    }
}

#' @export
nextElem.piterator <- function(I){
    if (I$replace){

    }else{
        if (I$n == I$r){
            if (is.null(I$currInd)) {
                # initialize the index
                if(I$is.multiset){
                    I$currInd = I$multiset
                }else{
                    I$currInd = (1:I$n)-1L
                }
                return(currElem(I))
            }else if(next_permutation(I$currInd)){
                return(currElem(I))
            }else{
                I$currInd = NULL
                return(NULL)
            }
        }else{
            if (is.null(I$currInd)) {
                # initialize the index
                if(I$is.multiset){
                    I$currInd = I$multiset
                }else{
                    I$currInd = (1:I$n)-1L
                }
                return(currElem(I))
            }else if(next_permutation(I$currInd)){
                return(currElem(I))
            }else{
                I$currInd = NULL
                return(NULL)
            }
        }
    }
}

#' @export
#' @method length piterator
length.piterator <- function(x){
    if (x$replace){

    }else{
        if (x$n == x$r){
            if (x$is.multiset){
                return(multichoose(x$f))
            }else{
                return(factorial(x$n))
            }
        }else{
            if (x$is.multiset){
                return(np.multiset(x$f, x$r))
            }else{
                return(prod(x$n:(x$n-x$r+1)))
            }
        }
    }
}