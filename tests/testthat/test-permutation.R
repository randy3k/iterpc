I = iterpc(5, ordered=TRUE)
expect_that(getnext(I)[3], equals(3))
expect_that(nrow(getall(I)), equals(factorial(5)))

I = iterpc(c("a","b","c"), ordered=TRUE)
getnext(I)
expect_that(getnext(I), equals(c("a","c","b")))

I = iterpc(c("a","a","c"), ordered=TRUE)
expect_that(nrow(getall(I)), equals(3))

I = iterpc(c("a","a","c","c"), 2, ordered=TRUE)
expect_that(nrow(getall(I)), equals(4))
getnext(I)
expect_that(getnext(I)[2], equals("c"))

I = iterpc(c("c","a","c","a"), 2, replace=TRUE, ordered=TRUE)
expect_that(nrow(getall(I)), equals(4))
expect_that(getnext(I,2)[2,2], equals("c"))