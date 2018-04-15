#' @export
getnext.comb <- function(I, d = 1L, drop = d == 1L){
    I$last <- I$object$getnext(d, drop = drop)
    I$last
}

#' @export
#' @method getlength comb
getlength.comb <- function(I, bigz=FALSE){
    if (I$replace){
        out <- choose(I$unique_n + I$r - 1, I$r)
    }else{
        if (I$is.multiset){
            out <- nc_multiset(I$f, I$r, TRUE)
        }else{
            out <- choose(I$n, I$r)
        }
    }
    convert_z(out, bigz)
}
