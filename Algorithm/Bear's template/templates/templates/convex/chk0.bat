g++ bf.cpp -o bf -g -O2
g++ dyn.cpp -o dyn -g -O2
g++ chk.cpp -o chk -g
dyn < in > out
bf < in > ans
fc ans out
echo %errorlevel%