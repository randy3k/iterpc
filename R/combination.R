initElem.citerator <- function(I){
    if (I$replace){

    }else{
        if (I$is.multiset){

        }else{
            I$curInd = (1:I$r)-1L
        }
    }
}

#' @export
nextElem.citerator <- function(I){
    if (I$replace){

    }else{
        if (I$is.multiset){

        }else{
            if (is.null(I$curInd)) {
                initElem(I)
                return(currElem(I))
            }else if(next_combination(I$curInd, I$n)){
                return(currElem(I))
            }else{
                I$curInd = NULL
                return(NULL)
            }
        }
    }
}



#' @export
allElem.citerator <- function(I){
    if (I$replace){

    }else{
        if (I$is.multiset){

        }else{
            initElem(I)
            C = currElem(I)
            while(next_combination(I$curInd,I$n)){
                C = rbind(C, currElem(I), deparse.level = 0)
            }
            I$curInd = NULL
            return(C)
        }
    }
}