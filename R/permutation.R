#' @export
getnext.perm <- function(I, d = 1L, drop = d == 1L){
    I$last <- I$object$getnext(d, drop = drop)
    I$last
}

#' @export
#' @method getlength perm
getlength.perm <- function(I, bigz=FALSE){
    if (I$replace){
        out <- I$unique_n^I$r
    }else{
        if (I$n == I$r){
            if (I$is.multiset){
                out <- multichoose(I$f, TRUE)
            }else{
                out <- factorial(I$n)
            }
        }else{
            if (I$is.multiset){
                out <- np_multiset(I$f, I$r, TRUE)
            }else{
                out <- prod(I$n:(I$n - I$r + 1))
            }
        }
    }
    convert_z(out, bigz)
}
