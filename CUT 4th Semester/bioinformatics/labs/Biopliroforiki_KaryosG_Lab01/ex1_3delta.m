%Ex. 1-3delta: Ena meso echi elastikotita ogkou B=1.8*10^9 N/m2 kaui piknotita r=1000 Kg/m3.
% Vrests to mikos kimatos otan perna kima me sichnotita f=1 MHz.
disp('Ipologiste to mikos kimatos ichou gia f=1MHz se malakous istous '), pause(0.01);
B = input('Enter the elastikotita ogkou: ');
r = 1000 ; % kg/m3
lamda = sqrt(B/r);
% Output the wavelength
%disp('The wavelength is : '), disp( lamda)
%fprintf('The answer in mm is %f\n', lamda), disp ('[mm]');
fprintf('The wavelength lamda, of sound is: %6.8f mm for a density of %8.2f Hz\n', lamda, r);
disp ('END of Program');
