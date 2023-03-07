function v = test_cm4
v = zeros (1, 25);
f = @(x) ((x + 1) * (x < 0) + (2*x*x + x)*(x >= 0 && x <= 3) + (x*x + 2*x)* (x > 3))
x = -2 : 0.5 : 10;
for i = 1 : 25
v(i) = f (x(i));
end
end