%ts = 0.000001;
%N = ts/(tf); % total samples in input signal
Plength = 512; %length of the amount of data being read of 4096 samples.
N = 4096*Plength
answr = zeros(2,N);
freq_res = 1000;
freq_range = (N/2)*freq_res
tf = 2*freq_range;
ts = N*(1/tf);
tN = linspace(0,ts,N);

%tsin = linspace(0,1,freq_range/freq_res);
%tetha = sin(pi*tsin);
f = 1;
damp = gaussian(freq_range,1/freq_range);
x = 1;
TEMP = zeros(2,N);
while f < freq_range
%or x = (pcc-1)*freq_range_div_sig+1:pcc*freq_range_div_sig

	if x > 1
		Temp2 = 1;%damp(x);
		TEMP(2,:) = Temp2*cos(2*pi*f*(tN));
		TEMP(1,:) = Temp2*sin(2*pi*f*(tN));
		answr += TEMP;
		x++;
		f = f + freq_res;
	else
		Temp2 = 0;
%		TEMP(2,:) = Temp2*cos(2*pi*f*(tN)+pi);
%		TEMP(1,:) = Temp2*cos(2*pi*f*(tN));
		answr += 0;
		x++;
		f = freq_res;
	endif
end
[A, B] = butter( 5 , [0.3 0.6] );

answr(1,:) = filter(A,B,answr(1,:));
answr(2,:) = filter(A,B,answr(2,:));
answr(:,:)/((freq_range)/freq_res)/N;
csvwrite('Inputtwodim4',answr);
figure(1);
plot(20*log(abs(fft(answr(1,:)/N))));
figure(2);
plot(angle(fft(answr(1,:)))/pi);
figure(3);
plot(20*log(abs(fft(answr(2,:)/N))));
figure(4);
plot(angle(fft(answr(2,:)))/pi);
