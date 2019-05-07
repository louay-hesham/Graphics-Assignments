#!/bin/octave -qf
1;

function th = f (t)
    %x = 2.074070951;
    %y = 1.939692621;
    %L1 = 2;
    %L2 = 1;
    arg_list = argv ();
    x = arg_list{1};
    y = arg_list{2};
    L1 = arg_list{3};
    L2 = arg_list{4};
    th(1) = L1*cos(t(1)) + L2*cos(t(1)+t(2)) - x;
    th(2) = L1*sin(t(1)) + L2*sin(t(1)+t(2)) - y;
endfunction

[th, info] = fsolve (@f, [0; 2*pi])
