% Ex1.4 Mia pigi iperichion echi akoustiki antistasi Z1=18*10^6 rayls.
% Efarmozete se isto me akoustiki antistasi Z2=1.6*10^6 rayls. Ypologiste
% to sintelesti anaklasis R, a) me kai b) choris stroma matching
disp('Ypologiste to sintelesti anaklasis R me stroma matching '), pause(0.01);
Z1 = input('Enter antistasi Z1: ');
Z2 = input('Enter antistasi Z2: ');
R = ((Z2-Z1)^2 / (Z2+Z1)^2) * 100;
fprintf('O sintelestis anaklasis me stroma matching ine [%4.2f]:  \n', R);
disp ('END of Program');
