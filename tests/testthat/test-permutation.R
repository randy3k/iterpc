I = iterator(5)
expect_that(nextElem(I)[3], equals(3))
expect_that(nrow(allElem(I)), equals(factorial(5)))

I = iterator(c("a","b","c"))
nextElem(I)
expect_that(nextElem(I), equals(c("a","c","b")))

I = iterator(c("a","a","c"))
expect_that(nrow(allElem(I)), equals(3))

I = iterator(c("a","a","c","c"), 2)
expect_that(nrow(allElem(I)), equals(4))