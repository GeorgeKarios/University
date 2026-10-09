%Ex1-1: Ipologiste to mikos kimatos ichou gia 2MHz se malakous istous
% c = 1540 m/sec Tachitita ichou
disp('Ipologiste to mikos kimatos ichou gia 2MHz se malakous istous '), pause(0.01);
%prompt = 'Enter the frequency of sound f:  '
f = input('Enter the frequency of sound f in HZ:  ');
c = 1540;
%Estimate the wavelength
lamda = c / f;
% Output the wavelength
%disp('The wavelength is : '), disp( lamda)
%fprintf('The answer in mm is %f\n', lamda), disp ('[mm]');
fprintf('The wavelength lamda, of sound is: %6.8f mm for a frequency of %8.2f Hz\n', lamda, f);
pause()
