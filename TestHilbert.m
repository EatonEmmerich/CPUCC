samplingFreq = 20*10^3; % sampling frequency
signal_frequency = 320; % radians/sec
signal_time = 0.05; % in seconds
N = signal_time/(1/samplingFreq); % total samples in input signal
t = linspace(0,signal_time,N);
Signal_no_noise = (sin(signal_frequency*t) + 20*sin((signal_frequency-10)*t));
%figure(1);
%plot(t,Signal_no_noise);
out = myhilbert(Signal_no_noise);
figure(2);
%f = linspace(-1,0,N/2+1);
%f = [linspace(0,1,N/2) f(1:(N/2))];
plot(t,imag(out));
figure(3);
out2 = hilbert(Signal_no_noise);
plot(t,imag(out2));
out = myhilbert(real(out));
figure(4);
plot(t,out);
figure(5);
out2 = hilbert(real(out2));
plot(t,out2);
