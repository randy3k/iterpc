I = iterator(5, 3, type="combination")
nextElem(I)
expect_that(nextElem(I)[3], equals(4))
expect_that(nrow(allElem(I)), equals(choose(5,3)))

I = iterator(c("a","b","c"), 3, type="combination")
nextElem(I)
expect_that(nextElem(I)[3], equals(NULL))

I = iterator(c("a","b","c"), 2, type="combination")
expect_that(nrow(allElem(I)), equals(choose(3,2)))

I = iterator(c("a","a","c","c"), 2, type="combination")
nextElem(I)
expect_that(nextElem(I)[2], equals("c"))
expect_that(nrow(allElem(I)), equals(3))