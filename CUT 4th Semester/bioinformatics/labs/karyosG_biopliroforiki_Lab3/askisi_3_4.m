%3.4
clc; clear; close all;

% data
t = (10:10:160)';  % ms
IA = [676;508;382;287;216;162;122;92;69;52;39;29;22;16;12;9];
IB = [737;603;494;404;331;271;222;182;149;122;100;82;67;55;45;37];
noise = 8;

% ypologizo cnr
CNR = (IB - IA) / noise;

% array- matrix me apotelesmata
Results = table(t, IA, IB, CNR)

% max cnr
[maxCNR, idx] = max(CNR);
fprintf('\nΜέγιστο CNR = %.3f στο t = %d ms\n', maxCNR, t(idx));

% graphiki
figure;
plot(t, CNR, '-o','LineWidth',1.5);
grid on;
xlabel('t (ms)');
ylabel('CNR');
title('Ασκηση 3.4 - CNR vs Time');
