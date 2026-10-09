%Ex. 1.5: Descriptive statistics
Temp = 1:10:110;
Volt = [12.3, 18.2, 25.4, 37.0, 43.6, 55.8, 62.0, 67.8, 70.4, 72.1, 73.0];
%Plot the curve Temp vs Volt
figure (1), plot(Temp, Volt), title('Temperature vs Voltage of a sensor');
xlabel('Input: Temperature'), ylabel('Voltage: Output');
%Estimate the slope of the curve at each pair
slope = diff(Volt) ./ diff(Temp);
%Find the maximum slope and its positon
mx_slope = max(slope);
maximum = max(max(slope));
% Find the offset
offset = Volt(1);
[x,y]=find(slope==maximum);
