samplingFreq = 2*10^9; % sampling frequency
Window_Size = 2^11; % size of window to cross multiply
%number_of_bodies = 5;
Num_Of_Antennas = 2;
signal_frequency = 40*10^8; % radians/sec
signal_time = 0.0001; % in seconds
N = signal_time/(1/samplingFreq); % total samples in input signal
Nsub = mod(N,Window_Size)
N = N-Nsub
Nfft = Window_Size%/2 % total samples in FFT output
Num_Of_Windows_Per_Signal = N/Window_Size;
P = Num_Of_Windows_Per_Signal
Number_Of_Signals = Num_Of_Antennas
Number_Of_Complex_Multiplications = 1/2*(Number_Of_Signals-1)*Number_Of_Signals
signal_to_noise_input = 1; % multiplied to noise then added to signal
Nyquist_freq = samplingFreq/2;
t = linspace(0,signal_time,N);
f = linspace(0,Nyquist_freq,5);
fs = linspace(0,1,Nfft/2);
fs_input = linspace(0,1,Nfft/2);
% Signal_no_noise = [(sin(signal_frequency*t(N/3:N*2/3-1)) + 20*sin((signal_frequency-1000)*t(N/3:N*2/3-1)))];
% input_hanning = [ 1/2-(1/2)*cos(2*pi*(1:N/3)/(N/3))];
% Signal_no_noise = Signal_no_noise.*input_hanning;
%figure(2);
%plot(t);
H = 3; % sizes of pictures.
W = 4;
Signal_no_noise = 1*(cos(signal_frequency*t) + cos((signal_frequency-3*10^7)*t)); %frequency noise
figure(1);
title('Input signal time domain','fontsize',14);
subplot(1,2,1);
plot(t(1:Nfft),abs(Signal_no_noise(1:Nfft)));
xlabel('time (s)','fontsize',14);
set(1,'paperunits','inches');
set(1,'paperorientation','portrait')
set(1,'papersize',[H,W]);
subplot(1,2,2);
plot(t(1:Nfft),angle(Signal_no_noise(1:Nfft)));
saveas(1,'inputsignaltime.svg','svg');
figure(2);
title('Input signal frequency domain','fontsize',14);
subplot(1,2,1);
fft_in = Signal_no_noise(1:Nfft);
plot(fs_input,20*log(abs(fft(fft_in)(1:Nfft/2)))/Nfft);
xlabel('f_s','fontsize',14);
set(2,'paperunits','inches');
set(2,'paperorientation','portrait');
set(2,'papersize',[H,W]);
subplot(1,2,2);
stem(fs_input,angle(fft(fft_in))(1:Nfft/2));
xlabel('f_s');
ylabel('angle');
saveas(2,'input freq.eps','eps');
%windowcoef = (Nfft)/f; % commonly used constant
Signal_no_noise_s = csvread('Inputtwodim4test');
Signal_no_noise_s = Signal_no_noise_s(:,1:N);
figure(102);
title('Antenna input signal 1 freq');
subplot(1,2,1);
fft_in = Signal_no_noise_s(1,1:Nfft);
plot(fs_input,20*log(abs(fft(fft_in)(1:Nfft/2)/Nfft)));
xlabel('f_s','fontsize',14);
set(102,'paperunits','inches');
set(102,'paperorientation','portrait');
set(102,'papersize',[H,W]);
subplot(1,2,2);
stem(fs_input,angle(fft(fft_in))(1:Nfft/2));
xlabel('f_s');
ylabel('angle');
saveas(102,'freqofantennain1.eps','eps');
figure(103);
title('Antenna input signal 3 freq');
subplot(1,2,1);
fft_in = Signal_no_noise_s(1,1:Nfft);
plot(fs_input,20*log(abs(fft(fft_in)(1:Nfft/2))/Nfft));
xlabel('f_s','fontsize',14);
set(102,'paperunits','inches');
set(102,'paperorientation','portrait');
set(102,'papersize',[H,W]);
subplot(1,2,2);
stem(fs_input,angle(fft(fft_in))(1:Nfft/2));
xlabel('f_s');
ylabel('angle');
saveas(103,'freqofantennain2.eps','eps');
Signalf = zeros(Num_Of_Windows_Per_Signal,Window_Size);
Signalfft = zeros(Number_Of_Signals,Nfft/2);
Signalmul = zeros(Number_Of_Complex_Multiplications,Nfft/2);
Signalout = zeros(1,Nfft/2);
Signalin = zeros(Number_Of_Signals,N);
analysis_filter = sinc(((0:(N-1))-N/2)/Window_Size);
%HanningWindow =0.53836-(0.46164)*cos(2*pi*(0:(N-1))/N);%EDIT, replaced with Hamming window
%EDIT replaced Hanning/hamming with blackman window.
HanningWindow = 0.42659 - 0.49656*cos(2*pi*(0:N-1)/N)+0.076849*cos(4*pi*(0:N-1)/N);
pre_filter = analysis_filter.*HanningWindow;
figure(48);
plot(t(1:N),pre_filter);
title('polyphase filter prefilter','fontsize',14);
xlabel('time(s)');
set(48,'paperunits','inches');
set(48,'paperorientation','portrait');
set(48,'papersize',[H,W]);
saveas(48,'polyphasepre.eps','eps');
% iterate every other signal

% Set up realtime signals
x2 = 1;
for x = 1:Num_Of_Antennas
	%Signal_no_noise_s = zeros(1,N);
    %for(z = 1:number_of_bodies)
    %    Signal_no_noise_s = Signal_no_noise_s + noise2(z)*e.^((((2*pi*f(z)*t)+noise1(z)*0.5*pi*(x-1))*i));
    %end
    Signalt = ((Signal_no_noise)+(Signal_no_noise_s(x,:))/signal_to_noise_input);
%add gaussian noise
    gaussnoise = rand(1,N);
    gaussnoise = gaussnoise - mean(gaussnoise);
    Signalt = Signalt + gaussnoise;
    figure(x+2);
    subplot(1,2,1);
    plot(t(1:N),abs(fft(Signalt(1:N))/N));
    xlabel('time(s)','fontsize',14);
    title('Antenna output signal','fontsize',14);
    set((x+2),'paperunits','inches');
    set((x+2),'paperorientation','portrait');
    set((x+2),'papersize',[H,W]);
    subplot(1,2,2);
    plot(t(1:N),angle(fft(Signalt(1:N))));
    xlabel('time(s)');
    ylabel('angle');
    name = ['a' num2str(x) 'outf.eps'];
    saveas(x+2,name,'eps');
    Signalin(x,:) = Signalt;

    %create overlap sequences:
    start = 1;
    window_c = Window_Size; % end of the window currently being shifted
    z = 1;
    TEMP = zeros(1,Window_Size);

    %DO POLYPHASE

    while window_c <= N
        Signalf(z,:) = (Signalt(start:(window_c)));
%       Signalf(z,:) = Signalt(1:Nfft);
	pre_part = pre_filter(start:(window_c));
	% add prefilter
	Signalf(z,:) = Signalf(z,:).*pre_part;
	%figure(z+100*x);
	%plot(angle(fft(Signalt(start:window_c))));
        start = window_c+1;
        window_c = window_c + Window_Size;
        TEMP = TEMP + Signalf(z,:);
        z = z + 1;
    end
    TEMP = fft(TEMP/P)/Nfft;
    Signalfft(x2,:) = TEMP(1:Nfft/2);
    x2 = x2 + 1;
    
end

% plot the outputs:
y = 0;
for x = 1:Num_Of_Antennas
	figure(x+2+Num_Of_Antennas);
	subplot(1,2,1);
	plot(fs,20*log(abs(Signalfft(x,1:Nfft/2))));
	title('after polyphase filter','fontsize',14);
	xlabel('f_s','fontsize',14);
	ylabel('dB','fontsize',14);
	set(x+2+Num_Of_Antennas,'paperunits','inches');
	set(x+2+Num_Of_Antennas,'paperorientation','portrait')
	set(x+2+Num_Of_Antennas,'papersize',[H,W]);
	name = ['pffb-' num2str(x) '.eps'];
	subplot(1,2,2);
	stem(fs,angle(Signalfft(x,1:Nfft/2)));
        xlabel('f_s');
	ylabel('angle');
	saveas((x+2+Num_Of_Antennas),name,'eps');
	%figure(96+x);
	%plot(fs,angle(Signalfft(1,1:Nfft/2).*conj(Signalfft(2,1:Nfft/2))));
end

% multiply and add
z = 1; % holds position, computation too complex for pre calculated indices here.
for x = 1:Number_Of_Signals
    for y = (x+1):Number_Of_Signals
        Signalmul(z,:) = Signalfft(x,:).*conj(Signalfft(y,:));
        z=z+1;
    end
end

for x = 1:Number_Of_Complex_Multiplications
    Signalout = Signalmul(x,:)+Signalout;
end

%figure(1);
%plot(t,Signal_no_noise);
% figure(2);
% plot(t(1:Window_Size),(pre_filter));
% figure(3);
% plot(t(1:Window_Size),(HanningWindow));
%figure(19);
%plot(fs,20*log(abs(Signalout)));
%Signalout = ifft(Signalout,N);
%figure (20);
%plot(t,20*log(abs(Signalout)));
figure (21);
subplot(1,2,1);
plot(fs,(20*log(abs((Signalout(1:Nfft/2))))));
title('output frequencys','fontsize',14);
xlabel('f_s','fontsize',14);
set(21,'paperunits','inches');
set(21,'paperorientation','portrait')
set(21,'papersize',[H,W]);
subplot(1,2,2);
stem(fs,angle(Signalout(1:Nfft/2)));
xlabel('f_s');
ylabel('angle');
saveas(21,'outf.eps','eps');

figure (22);
plot(angle(Signalout(1:Nfft/2)));
title('output angle');
xlabel('f_s');
hold on;
xlabel('f_s');
ylabel('angle');
hold off;
saveas(22,'output angle.eps','eps');
figure (23);
size14 = abs(Signalout(10))
angle14 = angle(Signalout(10))
ttta = angle(fft(Signal_no_noise_s(1,:)).*conj(fft(Signal_no_noise_s(2,:))));
%ttfa = angle(fft(Signalin(1,1:Nfft)).*conj(fft(Signalin(2,1:Nfft))));
%angle14 = ttfa(10)
%size15 = abs(Signalout(100))
%angle15 = angle(Signalout(100))
%angle15 = ttfa(100)
plot(linspace(0,1,N/2),ttta(1:N/2));
title('actual angles N = whole signal');
xlabel('f_s');
hold on;
xlabel('f_s');
ylabel('angle');
hold off;
saveas(23,'actual angles.eps','eps');
