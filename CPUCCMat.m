samplingFreq = 100*10^9; % sampling frequency
%f = 1; % number of overlapping signals
Window_Size = 2^9; % size of window to cross multiply
Num_Of_Antennas = 2;
signal_frequency = 40*10^9; % radians/sec
signal_time = 0.00000010; % in seconds
N = signal_time/(1/samplingFreq) % total samples in input signal
Nfft = Window_Size%/2 % total samples in FFT output
Num_Of_Windows_Per_Signal = ceil(N/Window_Size);
Number_Of_Signals = Num_Of_Antennas
Number_Of_Complex_Multiplications = 1/2*(Number_Of_Signals-1)*Number_Of_Signals
signal_to_noise_input = 0.5; % multiplied to noise then added to signal
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
Signal_no_noise = 20*(cos(signal_frequency*t) + sin((signal_frequency+15*10^9)*t)); %frequency noise
figure(1);
subplot(1,2,1);
plot(t(1:Nfft),abs(Signal_no_noise(1:Nfft)));
title('Input signal time domain','fontsize',14);
xlabel('time (s)','fontsize',14);
set(1,'paperunits','inches');
set(1,'paperorientation','portrait')
set(1,'papersize',[H,W]);
subplot(1,2,2);
plot(t(1:Nfft),angle(Signal_no_noise(1:Nfft)));
print(1,'input time.svg','-dsvg');
figure(2);
subplot(1,2,1);
fft_in = Signal_no_noise(1:Nfft);
plot(fs_input,20*log(abs(fft(fft_in)(1:Nfft/2))));
title('Input signal frequency domain','fontsize',14);
xlabel('f_s','fontsize',14);
set(2,'paperunits','inches');
set(2,'paperorientation','portrait');
set(2,'papersize',[H,W]);
subplot(1,2,2);
stem(fs_input,angle(fft(fft_in))(1:Nfft/2));
print(2,'input freq.svg','-dsvg');
%windowcoef = (Nfft)/f; % commonly used constant

Signalf = zeros(Num_Of_Windows_Per_Signal,Window_Size);
Signalfft = zeros(Number_Of_Signals,Nfft);
Signalmul = zeros(Number_Of_Complex_Multiplications,Nfft);
Signalout = zeros(1,Nfft);
Signalin = zeros(Number_Of_Signals,N);
analysis_filter = sinc(((1:Window_Size)-Window_Size/2)/Window_Size);
HanningWindow = 1/2-(1/2)*cos(2*pi*(1:Window_Size)/Window_Size);
pre_filter = analysis_filter.*HanningWindow;
figure(22);
plot(t(1:Window_Size),HanningWindow);
title('polyphase filter prefilter','fontsize',14);
xlabel('time(s)');
set(22,'paperunits','inches');
set(22,'paperorientation','portrait');
set(22,'papersize',[H,W]);
print(22,'polyphasepre.svg','-dsvg');
% iterate every other signal

% Set up realtime signals
noise1 = 2*rand(1,5)-1
noise2 = 2*rand(1,5)-1;
for x = 1:Num_Of_Antennas
    % EDIT: added delay on signals as antenna increases
%     TEMP = [zeros(1,10*x) Signal_no_noise zeros(1,N*2/3+1-(10*x))];
    Signal_no_noise_s = zeros(1,N);
    for(z = 1:5)
        Signal_no_noise_s = Signal_no_noise_s + noise2(z)*e.^((((2*pi*f(z)*t)+noise1(z)*0.5*pi*(x-1))*i));
    end
    Signalt = ((Signal_no_noise)+(Signal_no_noise_s)/signal_to_noise_input);
    figure(x+2);
    subplot(1,2,1);
    plot(t(1:N),abs(Signalt(1:N)));
    xlabel('time(s)','fontsize',14);
    title('Antenna output signal','fontsize',14);
    set((x+2),'paperunits','inches');
    set((x+2),'paperorientation','portrait');
    set((x+2),'papersize',[H,W]);
    subplot(1,2,2);
    plot(t(1:N),angle(Signalt(1:N)))
    name = ['a' num2str(x) 'outf.svg'];
    print(x+2,name,'-dsvg');
    Signalin(x,:) = Signalt;
    phases2 = noise2;
    %EDIT: removed: create overlap sequences:
       
    start = 1;
    window_c = (Window_Size); % end of the window currently being shifted
    z = 1;
    TEMP = zeros(1,Window_Size);
	%DO POLYPHASE
    while window_c < N
        Signalf(z,:) = (Signalt(start:(window_c)));
	Signalf(z,:) = Signalt(1:Nfft);
        % add prefilter
	Signalf(z,:) = Signalf(z,:).*pre_filter;
        start = window_c+1;
        window_c = window_c + Window_Size;
        TEMP = TEMP + Signalf(z,:);
        z = z +1;
    end
    TEMP = fft(TEMP/(z-1));
    Signalfft(x,:) = TEMP(1:Nfft);
end

% plot the outputs:
y = 0;
for x = 1:Num_Of_Antennas
	figure(x+2+Num_Of_Antennas);
	subplot(1,2,1);
	plot(fs,abs(Signalfft(x,1:Nfft/2)));
	title('after polyphase filter','fontsize',14);
	xlabel('f_s','fontsize',14);
	set(x+2+Num_Of_Antennas,'paperunits','inches');
	set(x+2+Num_Of_Antennas,'paperorientation','portrait')
	set(x+2+Num_Of_Antennas,'papersize',[H,W]);
	name = ['pffb-' num2str(x) '.svg'];
	subplot(1,2,2);
	stem(fs,angle(Signalfft(x,1:Nfft/2)));
	print((x+2+Num_Of_Antennas),name,'-dsvg');
	%figure(96+x);
	%plot(fs,angle(Signalfft(1,1:Nfft/2).*conj(Signalfft(2,1:Nfft/2))));
end

% multiply and add
z = 1; % holds position, computation too complex for pre calculated indices here.
for x = 1:Number_Of_Signals
    for y = (x+1):Number_Of_Signals
        Signalmul(z,:) = Signalfft(x,:).*conj(Signalfft(y,:))/Nfft;
        z=z+1;
    end
end

for x = 1:Number_Of_Complex_Multiplications
    Signalout = Signalmul(x,:)+Signalout;
end

Signalout = Signalout/(z-1);

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
print(21,'outf.svg','-dsvg');

figure (22);
plot(angle(Signalout(1:Nfft/2)));
figure (23);
size14 = abs(Signalout(10))
angle14 = angle(Signalout(10))
ttta = angle(fft(Signalin(1,:).*conj(fft(Signalin(2,:)))));
ttfa = angle(fft(Signalin(1,1:Nfft)).*conj(fft(Signalin(2,1:Nfft))));
angle14 = ttfa(10)
size15 = abs(Signalout(100))
angle15 = angle(Signalout(100))
angle15 = ttfa(100)
plot(ttfa(1:Nfft/2));
figure(24);
plot(phases2*pi);
figure(25);
plot(angle(ifft(Signalout)));
