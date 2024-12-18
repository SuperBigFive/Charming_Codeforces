g++ dyn.cpp -o dyn -g -O2
g++ gen.cpp -o gen -g -O2
gen 1000000000 1000000 1000000 0.0001 > in
dyn < in > out
echo %errorlevel%