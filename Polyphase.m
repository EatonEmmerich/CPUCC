SamplingFreq = 2*10^9;
Window_Size = 2^15;
%signal_time = 0.0001; % in seconds
P = 10
N = 1024
Window_Size
M = N*P%signal_time/(1/SamplingFreq);
%Msub = mod(N,Window_Size);
%M = M-Msub
i = 0:(M-1);
analysis_filter = sinc(((i)-M/2)/N);
hamming_window = 0.5-0.5*cos(2*pi*i/M);
prefilter = analysis_filter.*hamming_window;
input = csvread('inputtest.csv');%sin(i/SamplingFreq*0.5*10^9);
input = input(1,1:M);
output = zeros(1,N+1);
output = prefilter(1:(N)).*input(1:(N));
output += prefilter((1*N+1):(2*N)).*(input((1*N+1):(2*N)));
output += prefilter((2*N+1):(3*N)).*(input((2*N+1):(3*N)));
output += prefilter((3*N+1):(4*N)).*(input((3*N+1):(4*N)));
output += prefilter((4*N+1):(5*N)).*(input((4*N+1):(5*N)));
output += prefilter((5*N+1):(6*N)).*(input((5*N+1):(6*N)));
output += prefilter((6*N+1):(7*N)).*(input((6*N+1):(7*N)));
output += prefilter((7*N+1):(8*N)).*(input((7*N+1):(8*N)));
%output += prefilter((8*N+1):(9*N)).*(input((8*N+1):(9*N)));
%output += prefilter((9*N+1):(10*N)).*(input((9*N+1):(10*N)));
%output += prefilter((10*N+1):(11*N)).*(input((10*N+1):(11*N)));
%output += prefilter((11*N+1):(12*N)).*(input((11*N+1):(12*N)));
%output += prefilter((12*N+1):(13*N)).*(input((12*N+1):(13*N)));
%output += prefilter((13*N+1):(14*N)).*(input((13*N+1):(14*N)));
%output += prefilter((14*N+1):(15*N)).*(input((14*N+1):(15*N)));
%output += prefilter((15*N+1):(16*N)).*(input((15*N+1):(16*N)));
output = hilbert(output);

figure (1)
plot(20*log10(abs(fft(prefilter)/N)));
figure(2)
plot(angle(fft(prefilter)))
figure (3)
plot((i/SamplingFreq),prefilter);
figure(4)
length(output)
length(0:(N-1))
plot(0:(N/2-1),20*log10(abs(fft(output)/N*2))(1:N/2))
figure(5)
plot(0:(N/2-1),angle(fft(output)/N*2)(1:N/2))
figure(6)
length(i)
length(prefilter)
plot(i/SamplingFreq,input)
figure(7)
plot(i,20*log10(fft(input)/M));
figure(8)
plot(i,angle(fft(input)))
