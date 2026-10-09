%3.5
clc; clear; close all;

% data
t = (100:100:1600)';  % ms
IA = [280;468;594;678;735;773;798;815;827;834;840;843;845;847;848;849];
IB = [107;198;275;341;396;442;482;515;544;568;588;605;620;632;643;651];

noise = 8;

% vrisko CNR
CNR = (IA - IB) / noise;

% matrix me arithmous
Results = table(t, IA, IB, CNR)

% max CNR
[maxCNR, idx] = max(CNR);
fprintf('\nΜέγιστο CNR = %.3f στο t = %d ms\n', maxCNR, t(idx));

% grafiki
figure;
plot(t, CNR, '-o','LineWidth',1.5);
grid on;
xlabel('t (ms)');
ylabel('CNR');
title('Ασκηση 3.5 - CNR vs Time');
