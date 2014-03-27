\name{Iter}
\alias{Iter}
\title{Initialize a iterator for permuations or combinations}
\usage{
Iter(n, r = NULL, type = "permutation", replace = FALSE,
  is.multiset = length(n) > 1 && anyDuplicated(n) > 0)
}
\arguments{
  \item{n}{the length of the input sequence or the input
  sequence.}

  \item{r}{the length of the output sequence. If missing,
  equals to \code{n}.}

  \item{type}{either \code{permutation} or
  \code{combination}. Default is \code{permutation}.}

  \item{replace}{with/without replacement. Default is
  \code{FALSE}.}

  \item{is.multiset}{the source sequence is a multiset?
  \code{TRUE} if \code{n} is a vector of size >1 and
  contains duplicates.}
}
\value{
a permutation/combination iterator
}
\description{
Initialize a iterator for permuations or combinations
}

