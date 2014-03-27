\name{multichoose}
\alias{multichoose}
\title{Calculate mulinomial coefficient}
\usage{
multichoose(n)
}
\arguments{
  \item{n}{a vector of group sizes}
}
\value{
multinomial coefficient
}
\description{
Calculate mulinomial coefficient
}
\details{
This function calculate the multinomial coefficient
\deqn{\frac{(\sum n_j)!}{\prod n_j!}.}{(\sum n_j)! / \prod
n_j!.}

It will throw overflow error if the return value is too
large. And the result is not exactly precise if the
retunred value is larger than 2^53 due to limition of
integers.
}
\examples{
# (3+1+1)!/ (3! 1! 1!) = 20
multichoose(c(3,1,1))
}

