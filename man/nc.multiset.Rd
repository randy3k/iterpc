\name{nc.multiset}
\alias{nc.multiset}
\title{Calcuate the number of combinations of a multiset}
\usage{
nc.multiset(f, r)
}
\arguments{
  \item{f}{the frequencies of the mutliset}

  \item{r}{the number of object drawn from the multiset}
}
\value{
the number of combinations
}
\description{
Calcuate the number of combinations of a multiset
}
\examples{
x = c("a","a","b")
# possible combinations of size 2 are "aa" and "ab".
np.multiset(table(x), 2) # = 2
}

