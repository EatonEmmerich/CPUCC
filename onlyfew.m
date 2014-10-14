N = 2^20
samplefreq = 5000000
data = zeros(1,N);
t = (1:N)/samplefreq;
binfreq = 1.25*10^6
num = 2
for x = -num/2:num/2
	data += sin((x*10000+binfreq)*t-pi/2);
end
figure(1)
plot(20*log10(abs(fft(data))));
figure(2)
plot(angle(fft(data)));
