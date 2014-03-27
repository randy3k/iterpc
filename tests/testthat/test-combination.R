I = Iter(5, 3, type="combination")
getNext(I)
expect_that(getNext(I)[3], equals(4))
expect_that(nrow(getAll(I)), equals(choose(5,3)))

I = Iter(c("a","b","c"), 3, type="combination")
getNext(I)
expect_that(getNext(I)[3], equals(NULL))

I = Iter(c("a","b","c"), 2, type="combination")
expect_that(nrow(getAll(I)), equals(choose(3,2)))

I = Iter(c("a","a","c","c"), 2, type="combination")
getNext(I)
expect_that(getNext(I)[2], equals("c"))
expect_that(nrow(getAll(I)), equals(3))

I = Iter(5, 3, 2, type="combination",replace=TRUE)
getNext(I)
expect_that(getNext(I), equals(c(1,1,2)))
expect_that(nrow(getAll(I)), equals(35))