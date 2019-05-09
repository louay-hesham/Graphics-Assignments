1;

function f = angles_eqns(th)
    arg_list = argv ();
    L1 = arg_list{1};
    L2 = arg_list{2};
    x = arg_list{3};
    y = arg_list{4};
    f(1) = L1*cosd(th(1)) + L2*cosd(th(1) + th(2)) - x;
    f(2) = L1*sind(th(1)) + L2*sind(th(1) + th(2)) - y;
endfunction

[th, fval, info] = fsolve (@angles_eqns, [0; 0])
