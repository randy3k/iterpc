\name{np_multiset}
\alias{np_multiset}
\title{Calcuate the number of r-permutations of a multiset}
\usage{
np_multiset(f, r)
}
\arguments{
  \item{f}{the frequencies of the mutliset}

  \item{r}{the number of object drawn from the multiset}
}
\value{
the number of r-permutations
}
\description{
Calcuate the number of r-permutations of a multiset
}
\examples{
x = c("a","a","b")
# possible permutations of size 2 are "aa", "ab" and "ba".
np_multiset(table(x), 2) # = 3
}

