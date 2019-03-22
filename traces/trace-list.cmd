# Test performance of insert_tail, size, and reverse
option fail 0
option malloc 0
gsh 10000
newl
iel
flurt benchmark.txt time sl 0
showl
freel
newl
iel
flurt benchmark.txt time sl 1
showl
freel
newl
iel
flurt benchmark.txt time sl 2
showl
freel
gsh 20000
newl
iel
flurt benchmark.txt time sl 0
showl
freel
newl
iel
flurt benchmark.txt time sl 1
showl
freel
newl
iel
flurt benchmark.txt time sl 2
showl
freel
gsh 30000
newl
iel
flurt benchmark.txt time sl 0
showl
freel
newl
iel
flurt benchmark.txt time sl 1
showl
freel
newl
iel
flurt benchmark.txt time sl 2
showl
freel
gsh 40000
newl
iel
flurt benchmark.txt time sl 0
showl
freel
newl
iel
flurt benchmark.txt time sl 1
showl
freel
newl
iel
flurt benchmark.txt time sl 2
showl
freel
gsh 50000
newl
iel
flurt benchmark.txt time sl 0
showl
freel
newl
iel
flurt benchmark.txt time sl 1
showl
freel
newl
iel
flurt benchmark.txt time sl 2
showl
freel
