function get_angles(x, y, L1, L2)
    theta1=sym('theta1');
    theta2=sym('theta2');
    f1 = L1*cos(theta1) + L2*cos(theta1+theta2) - x;
    f2 = L1*sin(theta1) + L2*sin(theta1+theta2) - y;
    [theta1,theta2] = solve(f1,f2,theta1,theta2)
end
