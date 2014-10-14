N = 2^11
signalp = [0.0001 ones(1,N/2-1)];
signaln = ones(1,N/2);
for x = 1: N/2
	signalp(x) = signalp(x)*e.^(i*(1*pi*x/N-0*pi));
	signaln(x) = signaln(x)*e.^(i*(-1*pi*x/N+0*pi));
end



signal = [signalp flipdim(signaln)];
figure(7)
plot(angle(signal));
figure(8)
signal = ifft(signal);
signal = FFTPF1D(signal,2,10,1);
%[b a] = butter(2,0.01);
%signal = filter(b,a, signal);
%[b a] = butter(2,0.99);
%signal = filter(a,b, signal);
figure(1)
plot(20*log10(abs(fft(signal))))
figure(2)
plot(angle(fft(signal)));
figure(3)
plot(abs(signal));
figure(4)
plot(angle(signal))
