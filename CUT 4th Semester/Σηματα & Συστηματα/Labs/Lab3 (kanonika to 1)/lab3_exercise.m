clc;clear;close all;
%% Part 1-  ημιτονικο σήμα

Fs = 1000;            % sixnotita se hz
T = 2;            % diarkeia se deutera (s)
t = 0:1/Fs:T-1/Fs;      % xroniki diarkeia- 2 deutera (s)
f1 = 5;              % sixnotita 
A1 = 1;             % Amplitude

x1 = A1*sin(2*pi*f1*t);

figure;
plot(t, x1);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('Signal x1(t) = A1 sin(2πf1t)');

%% Part 2 - δεύτερο ημιτονικο σήμα

f2 = 10;               % sixnotita (hz)
A2 = 2;            % Amplitude
2 = A2*sin(2*pi*f2*t);

figure;
plot(t, x2);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('Signal x2(t) = A2 sin(2πf2t)');

%% Part 3 -  συνθετο σύστημα για n = 2,3,4
%% x_total = Σ n sin(5π n t)

n_values = [2 3 4];

for idx = 1:length(n_values)
    
    n = n_values(idx);
    x_total = zeros(size(t));
    
    figure;
    
    for k = 1:n
        
        component = k*sin(5*pi*k*t);
        x_total = x_total + component;
        
        subplot(n+1,1,k);
        plot(t, component);
        grid on;
        xlabel('Time (s)');
        ylabel('Amplitude');
        title(['Component for k = ', num2str(k)]);
        
    end
    
    subplot(n+1,1,n+1);
    plot(t, x_total, 'k');
    grid on;
    xlabel('Time (s)');
    ylabel('Amplitude');
    title(['Final Composite Signal for n = ', num2str(n)]);
    
end

%% Part 4 - Amplitude Mod => n=4

n = 4;
x_total = zeros(size(t));

for k = 1:n
    x_total = x_total + k*sin(5*pi*k*t);
end

A = 1;
B = 0.5;
fm = 1;               % mod sixnotita se hz

m = A + B*sin(2*pi*fm*t);
x_mod = m .* x_total;
figure;

subplot(3,1,1);
plot(t, x_total);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('Original Composite Signal (n=4)');

subplot(3,1,2);
plot(t, m);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('Amplitude Modulator m(t)');

subplot(3,1,3);
plot(t, x_mod);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('Amplitude Modulated Signal');

%% Extra Gaussian Noise

noise = randn(size(x_mod));   % Mean = 0, Std = 1
x_noisy = x_mod + noise;

figure;
plot(t, x_noisy);
grid on;
xlabel('Time (s)');
ylabel('Amplitude');
title('AM Signal with Gaussian Noise (mean=0, std=1)');