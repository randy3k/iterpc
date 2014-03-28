\docType{package}
\name{iterpc}
\alias{iterpc}
\alias{iterpc-package}
\title{Iterator for Permutations and Combinations}
\usage{
iterpc(x, r = NULL, ordered = FALSE, replace = FALSE,
  is.multiset = length(x) > 1 && anyDuplicated(x) > 0)
}
\arguments{
  \item{x}{the length of the input sequence or the input
  sequence.}

  \item{r}{the length of the output sequence. If missing,
  equals to length of \code{x}.}

  \item{ordered}{\code{TRUE} corresponses to permutation
  and \code{FALSE} corresponses to combinations.}

  \item{replace}{with/without replacement. Default is
  \code{FALSE}.}

  \item{is.multiset}{the source sequence is a multiset?
  \code{TRUE} if \code{x} contains duplicates.}
}
\value{
a permutation/combination iterator
}
\description{
Iterator for Permutations and Combinations

Initialize a iterator for permutations or combinations
}
\examples{
#1) all combinations of drawing 2 items from {1, 2, 3}
I = iterpc(5, 2)
getall(I)

#2) continuing 1), get combination by combination
I = iterpc(5, 2)
getnext(I) # return 1,2
getnext(I) # return 1,3
getnext(I,2) # return next 2 results

#3) all permutations of {1, 2, 3}
I = iterpc(3, ordered = TRUE)
getall(I)

#4) permutations of multiset
I = iterpc(c("a","a","b","c"), ordered = TRUE)
getall(I)

#5) combinations with replacement
I = iterpc(c("a","a","b","c"), 3, replace=TRUE)
getall(I)
}

