\docType{package}
\name{iterpc}
\alias{iterpc}
\alias{iterpc-package}
\title{Iterator for Permutations and Combinations}
\usage{
iterpc(n, r = NULL, ordered = TRUE, replace = FALSE,
  is.multiset = length(n) > 1 && anyDuplicated(n) > 0)
}
\arguments{
  \item{n}{the length of the input sequence or the input
  sequence.}

  \item{r}{the length of the output sequence. If missing,
  equals to \code{n}.}

  \item{ordered}{\code{TRUE} corresponses to permutation
  and \code{FALSE} corresponses to combinations.}

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
Iterator for Permutations and Combinations

Initialize a iterator for permutations or combinations
}

