# prepare the package for release
PKGNAME := $(shell sed -n "s/Package: *\([^ ]*\)/\1/p" DESCRIPTION)
PKGVERS := $(shell sed -n "s/Version: *\([^ ]*\)/\1/p" DESCRIPTION)
PKGSRC  := $(shell basename `pwd`)

docs: roxygen
	R --slave -e "pkgdown::build_site()"

install: roxygen
	R CMD INSTALL --no-multiarch --with-keep.source --install-tests .

check: roxygen
	R CMD CHECK --as-cran .

roxygen:
	R --slave  -e "roxygen2::roxygenize('.', roclets=c('rd', 'namespace'))"
