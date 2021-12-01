#!/bin/sh

set -e
./$1 $2 | diff $3 -
echo $1 PASS