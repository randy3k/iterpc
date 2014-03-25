\name{iterator}
\alias{iterator}
\title{Initialize a iterator for permuations or combinations}
\usage{
iterator(n = NULL, r = NULL, x = NULL, type = "permutation",
  replace = FALSE, is.multiset = anyDuplicated(x) > 0)
}
\arguments{
  \item{n}{the length of the input sequence. If \code{x} is
  given, \code{n} can be missing.}

  \item{r}{the length of the output sequence. If missing,
  equals to \code{n}.}

  \item{x}{(optional) the source sequence.}

  \item{type}{either \code{permutation} or
  \code{combination}. Default is \code{permutation}.}

  \item{replace}{with/without replacement. Default is
  \code{FALSE}.}

  \item{is.multiset}{the source sequence is a multiset?
  Default: \code{TRUE} if \code{x} contains replicates,
  otherwise \code{FALSE}.}
}
\value{
a permutation/combination iterator
}
\description{
Initialize a iterator for permuations or combinations
}

