tf = 1/(2*10^9);
%ts = 0.000001;
%N = ts/(tf); % total samples in input signal
N = 4096*16
ts = N*tf;
answr = zeros(2,N);
tN = linspace(0,ts,N);
c = 299792458;
freq_range = 0.8*10^9;
freq_res = 1000;
%tsin = linspace(0,1,freq_range/freq_res);
%tetha = sin(pi*tsin);
f = 0.1*10^9;
countsamples = (freq_range-f)/freq_res
damp = gaussian(countsamples,1/countsamples*10);
x = 1;
TEMP = zeros(2,N);
while f < freq_range
%or x = (pcc-1)*freq_range_div_sig+1:pcc*freq_range_div_sig
	Temp2 = damp(x);
	TEMP(2,:) = Temp2*cos(2*pi*f*(tN)+0.5);
	TEMP(1,:) = Temp2*cos(2*pi*f*(tN));
	answr += TEMP;
	x++;
	f = f + freq_res;
end
%[A, B] = butter(5,0.9);

%answr(1,:) = filter(A,B,answr(1,:));
%answr(2,:) = filter(A,B,answr(2,:));
answr(:,:)/((freq_range)/freq_res)/N;
csvwrite('Inputtwodim4',answr);
figure(1);
plot(20*log(abs(fft(answr(1,:)/N))));
figure(2);
plot(angle(fft(answr(1,:))));
figure(3);
plot(20*log(abs(fft(answr(2,:)/N))));
figure(4);
plot(angle(fft(answr(2,:))));
