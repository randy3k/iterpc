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

The result is not reliable if the retunred value is too
large (around 2^53) due to limition of integers.
}
\examples{
# (3+1+1)!/ (3! 1! 1!) = 20
multichoose(c(3,1,1))
}

