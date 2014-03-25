initElem.piterator <- function(I){
    if (I$replace){

    }else{
        if (I$n == I$r){
            if(I$is.multiset){
                I$curInd = I$multiset
            }else{
                I$curInd = (1:I$n)-1L
            }
        }
    }
}


#' @export
allElem.piterator <- function(I){
    if (I$replace){

    }else{
        if (I$n == I$r){
            initElem(I)
            P = currElem(I)
            while(next_permutation(I$curInd)){
                P = rbind(P, currElem(I), deparse.level = 0)
            }
            I$curInd = NULL
            return(P)
        }
    }
}

#' @export
nextElem.piterator <- function(I){
    if (I$replace){

    }else{
        if (I$n == I$r){
            if (is.null(I$curInd)) {
                initElem(I)
                return(currElem(I))
            }else if(next_permutation(I$curInd)){
                return(currElem(I))
            }else{
                I$curInd = NULL
                return(NULL)
            }
        }
    }
}