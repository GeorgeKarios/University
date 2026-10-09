% Ex3-7: Given the following values plot, (i) the signal intensity versus 
% time for the two different tissues.
t = [10:10:160];
Ia = [676;508;382;287;216;162;122;92;69;52;39;29;22;16;12;9];
Ib = [737;603;494;404;331;272;222;182;149;122;100;82;67;55;45;37];

figure(1), plot(t, Ia, '-o'), xlabel('t [ms]'); ylabel('Signal Intensity');
hold on, plot(t, Ib, '-*')
legend('IA', 'IB');
hold off;

% Find the T2 for A and B tissues
TA2 = (37*max(Ia))/100;
TB2 = (37*max(Ib))/100;

% Plotting points
hold on;
plot(t(1), Ia(1), 'r*');
plot(t(1), Ib(1), 'b*');

fprintf('The time for tissue A is: %5.2f secs and the time for the tissue B is: %5.2f secs 

% Find the contrast between the two tissues and plot C=(a-b)/noise;
noise = input('Enter the noise : ');
