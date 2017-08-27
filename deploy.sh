#!/bin/sh

# deploy to the gh-pages branch of the same repo
set -e

R --slave -e "devtools::install_github('hadley/pkgdown')"
R --slave -e "devtools::install_github('r-lib/pkgload')"
R --slave -e "library(pkgdown);build_site()"

cd ..

if [ -z "$(git ls-remote --heads https://github.com/randy3k/iterpc | grep gh-pages)" ]
then
    echo "make gh-pages"
    mkdir gh-pages
    cd gh-pages
    git init
    git checkout -b gh-pages
    git remote add origin https://${GITHUB_PAT}@github.com/randy3k/iterpc.git > /dev/null 2>&1
else
    git clone --branch gh-pages https://${GITHUB_PAT}@github.com/randy3k/iterpc.git gh-pages > /dev/null 2>&1
    cd gh-pages
fi
echo "copy webpages to here"
rm -Rf *
cp -Rf ../iterpc/docs/. ./
git config user.email "randy.cs.lai@gmail.com"
git config user.name "Randy Lai"
git add -A :/
echo "committing"
git diff --quiet --exit-code --cached || git commit -m "Deploy site at $(date)"
echo "deploy sites"
git push -u origin gh-pages:gh-pages > /dev/null 2>&1
