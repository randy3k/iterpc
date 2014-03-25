I = iterator(5, 3, type="combination")
nextElem(I)
expect_that(nextElem(I)[3], equals(4))
expect_that(nrow(allElem(I)), equals(choose(5,3)))