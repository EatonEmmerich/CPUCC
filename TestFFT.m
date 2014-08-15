samplingFreq = 20*10^3; % sampling frequency
signal_frequency = 240; % radians/sec
signal_time = 1; % in seconds
N = signal_time/(1/samplingFreq); % total samples in input signal
t = linspace(0,signal_time,N);
Signal_no_noise = (cos(signal_frequency*t) + 20*sin((signal_frequency+81)*t));
f = linspace(-1,0,N/2+1);
f = [linspace(0,1,N/2) f(1:(N/2))];
out = fft(Signal_no_noise);
figure(1);
stem (f,real(out));
out2 = myfft(Signal_no_noise);
figure(2);

