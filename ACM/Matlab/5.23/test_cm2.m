function [maxvalue, maxidx] = test_cm2
rand ('seed', 127)
v = round (200 * rand (1, 1000));
[maxvalue, maxidx] = max(v)
end