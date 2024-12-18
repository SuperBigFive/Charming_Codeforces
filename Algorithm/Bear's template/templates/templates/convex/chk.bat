g++ gen.cpp -o gen -g
g++ bf.cpp -o bf -g
g++ dyn.cpp -o dyn -g
g++ chk.cpp -o chk -g
:f
gen 1000 1000 20000 0.002 > in
dyn < in > out
bf < in > ans
fc out ans
if %errorlevel% == 0 goto f
echo %errorlevel%
:e