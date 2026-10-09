%Exercises Chapter 3:
%Ex3-5:
%Enas istos echi kathari magnitisi T1=2 sec. An i T1 mideniszotan, poso chrono tha pari gia tin kathari magnitisi na anaktisi to 98% tis
disp('Chronos pou chriazete in kathari magnitisi gia na pai sto 98% tiw '), pause(0.01);
%Draw the M=Mz/M0
t = [0:1:9]; T1 = 2.0 *(ones(1,10));
M = ones (1, 10)-exp(-t./T1);
%f = input('Enter the frequency of sound f in HZ: ');
%Plot the M vs t
%Find the 98% of the hight for a specific time
time = round (-1.0 * log(1-0.98) );
M_at_time = M(time-1);
fprintf('The Magnetizion M : %6.8f mm for a time of %2.1f secs\n', M_at_time, time);
figure, plot (t, M); title(' Kathari Magnitisi'); 
xlabel (' Relaxation time [sec]'); ylabel ('Kathari Magnitisi Mz/M0');
legend ( 'Mz/M0'), hold on, plot(time-1, M(time), 'r*');
