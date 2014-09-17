t = 1/(1*10^9);
N = 50000;
answr = zeros(1,N);
phi = [pi/4 -pi/160 0 -pi/800]
ts = (1:N)*t;
pc = 4
%sin(2*pi*f*t+\tetha)
freq_range = 0.5*10^9;
freq_res = 1000;
freq_start = 1000;
freq_range_div_sig = freq_range/pc;
count = 0;
for pcc = 1:pc
	pn = phi(pcc)
	x = (pcc-1)*freq_range_div_sig;
	if (pcc-1) == 0
		x = x + freq_start
	end
	while x < pcc*freq_range_div_sig
%	for x = (pcc-1)*freq_range_div_sig+1:pcc*freq_range_div_sig
		x = x + freq_res;
		TEMP = sin(2*pi*x*(ts+pn));
		answr += TEMP;
		count ++;
	end
end
count
csvwrite('InputSignal2',answr);
figure(1);
plot(abs(fft(answr)));
figure(2);
plot(angle(fft(answr)));
