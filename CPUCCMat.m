samplingFreq = 100*10^9; % sampling frequency
f = 4; % number of overlapping signals
Window_Size = 2048; % size of window to cross multiply
Num_Of_Antennas = 4;
signal_frequency = 40*10^9; % radians/sec
signal_time = 0.00000004; % in seconds
N = signal_time/(1/samplingFreq) % total samples in input signal
Nfft = Window_Size/2 % total samples in FFT output
Num_Of_Windows_Per_Signal = ceil(N/Window_Size);
Number_Of_Signals = Num_Of_Antennas*f
Number_Of_Complex_Multiplications = 1/2*(Number_Of_Signals-1)*Number_Of_Signals
signal_to_noise_input = 1; % multiplied to noise then added to signal
t = linspace(0,signal_time,N);
fs = linspace(0,1,Nfft);
fs_input = linspace(0,1,Window_Size);
% Signal_no_noise = [(sin(signal_frequency*t(N/3:N*2/3-1)) + 20*sin((signal_frequency-1000)*t(N/3:N*2/3-1)))];
% input_hanning = [ 1/2-(1/2)*cos(2*pi*(1:N/3)/(N/3))];
% Signal_no_noise = Signal_no_noise.*input_hanning;
%figure(2);
%plot(t);
H = 3; % sizes of pictures.
W = 4;
Signal_no_noise = (20*cos(signal_frequency*t) + sin((signal_frequency+15*10^9)*t)); %frequency noise
Signal_no_noise_s = (2*rand(1,N))-1 + ((2*rand(1,N)-1)*i);
Signal_no_noise = Signal_no_noise + Signal_no_noise_s;
figure(1);
plot(t(1:N),Signal_no_noise(1:N));
title('Input signal time domain','fontsize',14);
xlabel('time (s)','fontsize',14);
set(1,'paperunits','inches');
set(1,'paperorientation','portrait')
set(1,'papersize',[H,W]);
print(1,'input time.svg','-dsvg');
figure(2);
plot(fs_input,20*log(abs(fft(Signal_no_noise(1:Window_Size)))));
title('Input signal frequency domain','fontsize',14);
xlabel('f_s','fontsize',14);
set(2,'paperunits','inches');
set(2,'paperorientation','portrait');
set(2,'papersize',[H,W]);
print(2,'input freq.svg','-dsvg');
windowcoef = (N/2)/f; % commonly used constant

Signalf = zeros(Num_Of_Windows_Per_Signal,Window_Size);
Signalfft = zeros(Number_Of_Signals,Nfft);
Signalmul = zeros(Number_Of_Complex_Multiplications,Nfft);
Signalout = zeros(1,Nfft);
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
for x = 1:Num_Of_Antennas
    noise = 2*rand(1,N)-1;
    % EDIT: added delay on signals as antenna increases
%     TEMP = [zeros(1,10*x) Signal_no_noise zeros(1,N*2/3+1-(10*x))];
    Signalt = noise+(Signal_no_noise/signal_to_noise_input);
    figure(x+2);
    plot(t(1:N),Signalt(1:N));
    xlabel('time(s)','fontsize',14);
    title('Antenna output signal','fontsize',14);
    set((x+2),'paperunits','inches');
    set((x+2),'paperorientation','portrait');
    set((x+2),'papersize',[H,W]);
    name = ['a' num2str(x) 'outf.svg'];
    print(x+2,name,'-dsvg');
    % create overlap sequences:
    
    for y = 1:f
        start = 1;
        window_c = ceil(((1/f)*y)*Window_Size); % end of the window currently being shifted
        z = 1;
        TEMP = zeros(1,Window_Size);
        while window_c < N
            Signalf(z,:) = [zeros(1,Window_Size-(window_c-start)) (Signalt(start:(window_c-1)))];
            % add prefilter
            Signalf(z,:) = hilbert(Signalf(z,:).*pre_filter);
            %TEMP = fft(Signalf);
            %Signalfft((x),i,:) = TEMP(1:Nfft);
            start = window_c;
            window_c = window_c + Window_Size;
            TEMP = TEMP + Signalf(z,:);
            z = z +1;
        end
        TEMP = fft(TEMP/(z-1));
        Signalfft((x-1)*f+y,:) = TEMP(1:Nfft);
    end
end

% plot the outputs:
y = 0;
for x = 1:Num_Of_Antennas
	for(y = 1:f)
		figure((x-1)*y+y+2+Num_Of_Antennas);
		plot(fs,Signalfft(x,:));
		title('after polyphase filter','fontsize',14);
		xlabel('f_s','fontsize',14);
		set((x-1)*y+y+2+Num_Of_Antennas,'paperunits','inches');
		set((x-1)*y+y+2+Num_Of_Antennas,'paperorientation','portrait')
		set((x-1)*y+y+2+Num_Of_Antennas,'papersize',[H,W]);
		name = ['pffb-' num2str(x) '-' num2str(y) '.svg'];
		name
		print((x+2+Num_Of_Antennas),name,'-dsvg');
	end
end

% multiply and add
z = 1; % holds position, computation too complex for pre calculated indices here.
for x = 1:Number_Of_Signals
    for y = (x+1):Number_Of_Signals
        Signalmul(z,:) = Signalfft(x,:).*Signalfft(y,:)/Nfft;
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
plot(fs,(20*log(abs((Signalout)))));
title('output frequencys','fontsize',14);
xlabel('f_s','fontsize',14);
set(21,'paperunits','inches');
set(21,'paperorientation','portrait')
set(21,'papersize',[H,W]);
print(21,'outf.svg','-dsvg');
