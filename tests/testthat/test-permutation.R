I = Iter(5)
expect_that(getNext(I)[3], equals(3))
expect_that(nrow(getAll(I)), equals(factorial(5)))

I = Iter(c("a","b","c"))
getNext(I)
expect_that(getNext(I), equals(c("a","c","b")))

I = Iter(c("a","a","c"))
expect_that(nrow(getAll(I)), equals(3))

I = Iter(c("a","a","c","c"), 2)
expect_that(nrow(getAll(I)), equals(4))
getNext(I)
expect_that(getNext(I)[2], equals("c"))

I = Iter(c("c","a","c","a"), 2, replace=TRUE)
expect_that(nrow(getAll(I)), equals(4))
expect_that(getNext(I,2)[2,2], equals("c"))