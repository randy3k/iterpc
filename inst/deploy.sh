#!/bin/sh

# deploy to the gh-pages branch of the same repo
set -e

R --slave -e "library(staticdocs);build_site()"

cd ..

if [ -z "$(git ls-remote --heads https://github.com/randy3k/iterpc | grep gh-pages)" ]
then
    echo "make gh-pages"
    mkdir gh-pages
    cd gh-pages
    git init
    git checkout -b gh-pages
    git remote add origin https://${GH_TOKEN}@github.com/randy3k/iterpc.git
else
    git clone --branch gh-pages https://${GH_TOKEN}@github.com/randy3k/iterpc.git gh-pages
    cd gh-pages
fi
echo "copy webpages from to here"
rm -Rf *
cp -Rf ../iterpc/inst/web/. ./
git config user.email "randy.cs.lai@gmail.com"
git config user.name "Randy Lai"
git add -A :/
echo "committing"
git diff --quiet --exit-code --cached || git commit -m "Deploy site at $(date)"
echo "deploy sites"
git push -u origin gh-pages:gh-pages
