clc;clear;close all;

% Lab 4  RC Circuit
% R=1kΩ, C=1μF, vin(t)=5V (t>=0), vc(0)=0         RC * dvc/dt + vc(t) = vin(t)


R = 1e3;      %om
C = 1e-6;    %Farad
Vin = 5;     % eisagogi (Volts)
tau = R*C;    % sthathera Time
tspan = [0 6*tau];
vc0 = 0;
% dvc/dt = (Vin - vc)/(R*C)
f = @(t,vc) (Vin - vc)/(R*C);
[t, vc] = ode45(f, tspan, vc0);
figure;
plot(t, vc, 'LineWidth', 1.6);
grid on;
xlabel('Time (s)');
ylabel('v_c(t) (V)');
title('RC Circuit Response (0 \le t \le 6\tau)');
