samplingFreq = 2*10^4; % sampling frequency
f = 7; % number of overlapping signals
Window_Size = 65536*8*16/1024; % size of window to cross multiply
Num_Of_Antennas = 2;
signal_frequency = 324000; % radians/sec
signal_time = 2; % in seconds
N = signal_time/(1/samplingFreq) % total samples in input signal
Nfft = Window_Size/2 % total samples in FFT output
Num_Of_Windows_Per_Signal = ceil(N/Window_Size);
Number_Of_Signals = Num_Of_Antennas*f
Number_Of_Antenna_Signals = Num_Of_Antennas*f;
Number_Of_Complex_Multiplications = 1/2*(Number_Of_Antenna_Signals-1)*Number_Of_Antenna_Signals
signal_to_noise_input = 1; % multiplied to noise then added to signal
t = linspace(0,signal_time,N);
% Signal_no_noise = [(sin(signal_frequency*t(N/3:N*2/3-1)) + 20*sin((signal_frequency-1000)*t(N/3:N*2/3-1)))];
% input_hanning = [ 1/2-(1/2)*cos(2*pi*(1:N/3)/(N/3))];
% Signal_no_noise = Signal_no_noise.*input_hanning;
%figure(2);
%plot(t);
Signal_no_noise = (20*sin(signal_frequency*t) + 20*sin((signal_frequency+1000000)*t));
%plot(20*log(abs(fft(Signal_no_noise))));
windowcoef = (N/2)/f; % commonly used constant
fs = linspace(0,1,Nfft);
%Signals = zeros(Num_Of_Antennas,N);
Signalf = zeros(Num_Of_Windows_Per_Signal,Window_Size);
Signalfft = zeros(Number_Of_Antenna_Signals,Nfft);
Signalmul = zeros(Number_Of_Complex_Multiplications,Nfft);
Signalout = zeros(1,Nfft);
analysis_filter = sinc(((1:Window_Size)-Window_Size/2)/Window_Size);
HanningWindow = 1/2-(1/2)*cos(2*pi*(1:Window_Size)/Window_Size);
pre_filter = analysis_filter.*HanningWindow;
figure(1);
plot(HanningWindow);
% iterate every other signal

% Set up realtime signals
for x = 1:Num_Of_Antennas
    noise = 2*rand(1,N)-1;
    % EDIT: added delay on signals as antenna increases
%     TEMP = [zeros(1,10*x) Signal_no_noise zeros(1,N*2/3+1-(10*x))];
    Signalt = noise+(Signal_no_noise/signal_to_noise_input);
    % create overlap sequences:
    
    for y = 1:f
        start = 1;
        window_c = ceil(((1/f)*y)*Window_Size) % end of the window currently being shifted
        i = 1;
        TEMP = zeros(1,Window_Size);
        while window_c < N
            Signalf(i,:) = [zeros(1,Window_Size-(window_c-start)) (Signalt(start:(window_c-1)))];
            % add prefilter
            Signalf(i,:) = hilbert(Signalf(i,:).*pre_filter);
            %TEMP = fft(Signalf);
            %Signalfft((x),i,:) = TEMP(1:Nfft);
            start = window_c;
            window_c = window_c + Window_Size;
            TEMP = TEMP + Signalf(i,:);
            i = i +1;
        end
        TEMP = fft(TEMP/(i-1));
        Signalfft(x,:) = TEMP(1:Nfft);
    end
end

%experimental!!!!
% multiply and add
z = 1; % holds position, computation too complex for indices here.
for x = 1:Number_Of_Antenna_Signals
    for y = x:Number_Of_Antenna_Signals
        Signalmul(z,:) = Signalfft(x,:).*Signalfft(y,:)/Nfft;
        z=z+1;
    end
end

for x = 1:Number_Of_Complex_Multiplications
    Signalout = Signalmul(x,:)+Signalout;
end

Signalout = Signalout/Number_Of_Complex_Multiplications;


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
stem(fs,(20*log(abs((Signalout)))));
