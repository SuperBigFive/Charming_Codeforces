g++ gen.cpp -o gen
g++ inv.cpp -o inv
g++ chk.cpp -o chk
:loop
gen 100 10007 > in
inv < in > out
math < gen.mma
chk.exe
if %errorlevel% == 0 goto loop