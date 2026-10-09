clc;clear;close all;

% Lab 4 RLC kikloma
% R=3Ω, C=1mF, L=1mH vc(0)=0, dvc/dt(0)=0

R = 3;        % om
C = 1e-3; %farad
L = 1e-3;     %henry
Vin = 5;    %(Volts)
tau = 2*L/R;  %Time stathera
tspan = [0 20*tau];

%State metablites   x1=vc x2=dvc/dt   x1'=x2    x2'=( (1/C)*Vin - R*x2 - (1/C)*x1 ) / L
f = @(t,x) [ ...
    x(2); ...
    ((Vin/C) - R*x(2) - (1/C)*x(1))/L ...
];
x0 = [0; 0];
[t, x] = ode45(f, tspan, x0);
vc = x(:,1);
figure;
plot(t, vc, 'LineWidth', 1.6);
grid on;
xlabel('Time (s)');
ylabel('v_c(t) (V)');
title('RLC Circuit Response (0 \le t \le 20\tau)');