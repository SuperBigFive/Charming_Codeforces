clear
clc
A=[1 2 3;4 5 6;7 8 9]
b=[2 1 3 4 5]'
C=[1 3 4;2 3 4;3 4 5]
x=[7 2 3]
[d,idx]=max(x)
e=max(max(x))
[g,idx2]=sort(b,'descend')
idx=A(A>=C)
B=A'
h=B(idx)