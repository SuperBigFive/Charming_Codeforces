g++ gen.cpp -o gen -g
:loop
gen 100 10000000000 > in
sol < in > out
std < in > ans
fc out ans
if %errorlevel% == 0 goto loop