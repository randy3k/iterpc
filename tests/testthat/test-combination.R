I = iterpc(5, 3, ordered=FALSE)
getnext(I)
expect_that(getnext(I)[3], equals(4))
expect_that(nrow(getall(I)), equals(choose(5,3)))

I = iterpc(c("a","b","c"), 3, ordered=FALSE)
getnext(I)
expect_that(getnext(I)[3], equals(NULL))

I = iterpc(c("a","b","c"), 2, ordered=FALSE)
expect_that(nrow(getall(I)), equals(choose(3,2)))

I = iterpc(c("a","a","c","c"), 2, ordered=FALSE)
getnext(I)
expect_that(getnext(I)[2], equals("c"))
expect_that(nrow(getall(I)), equals(3))

I = iterpc(5, 3, 2, ordered=FALSE,replace=TRUE)
getnext(I)
expect_that(getnext(I), equals(c(1,1,2)))
expect_that(nrow(getall(I)), equals(35))