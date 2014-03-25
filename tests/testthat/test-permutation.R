I = iterator(5)
expect_that(nextElem(I)[3], equals(3))
expect_that(nrow(allElem(I)), equals(factorial(5)))
