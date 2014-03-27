\name{np.multiset}
\alias{np.multiset}
\title{Calcuate the number of r-permutations of a multiset}
\usage{
np.multiset(f, r)
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
np.multiset(table(x), 2) # = 3
}

